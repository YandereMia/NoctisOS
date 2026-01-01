# ==========================
# Directories
# ==========================
BOOT_DIR := src/boot
SRC_DIR := src
BUILD_DIR := build
ISO_DIR := isofiles

# ==========================
# Compiler & flags
# ==========================
CC := gcc
CFLAGS := -m32 -ffreestanding -O2 -Wall -Wextra -fno-stack-protector

# ==========================
# Linker
# ==========================
LD := ld
LDFLAGS := -m elf_i386 -T linker.ld

# ==========================
# Sources & objects
# ==========================
# Find all ASM (.s or .asm) and C sources recursively
ASRCS := $(shell find $(BOOT_DIR) -name '*.s' -o -name '*.asm')
CSRCS := $(shell find $(SRC_DIR) -name '*.c')

# Map sources to objects in build/
AOBJS := $(patsubst $(BOOT_DIR)/%.s,$(BUILD_DIR)/%.o,$(shell find $(BOOT_DIR) -name '*.s'))
AOBJS += $(patsubst $(BOOT_DIR)/%.asm,$(BUILD_DIR)/%.o,$(shell find $(BOOT_DIR) -name '*.asm'))
COBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(CSRCS))

# All objects
OBJS := $(COBJS) $(AOBJS)

# ==========================
# Targets
# ==========================
KERNEL := kernel.bin
ISO := NoctisOS.iso

# ==========================
# Assemble ASM files (.s)
# ==========================
$(BUILD_DIR)/%.o: $(BOOT_DIR)/%.s
	@mkdir -p $(dir $@)
	nasm -f elf32 -I $(BOOT_DIR) $< -o $@

# ==========================
# Assemble ASM files (.asm)
# ==========================
$(BUILD_DIR)/%.o: $(BOOT_DIR)/%.asm
	@mkdir -p $(dir $@)
	nasm -f elf32 -I $(BOOT_DIR) $< -o $@

# ==========================
# Default target
# ==========================
all: $(KERNEL) $(ISO)
# ==========================
# Compile C files
# ==========================
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ==========================
# Link kernel
# ==========================
$(KERNEL): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

# ==========================
# Prepare ISO files
# ==========================
$(ISO_DIR)/boot/$(KERNEL): $(KERNEL)
	@mkdir -p $(ISO_DIR)/boot
	cp $< $@

$(ISO_DIR)/boot/grub/grub.cfg:
	@mkdir -p $(ISO_DIR)/boot/grub
	@echo 'set timeout=5' > $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'set default=0' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo 'menuentry "NoctisOS 0.1" {' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '    multiboot /boot/$(KERNEL)' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '    boot' >> $(ISO_DIR)/boot/grub/grub.cfg
	@echo '}' >> $(ISO_DIR)/boot/grub/grub.cfg

# ==========================
# Build ISO
# ==========================
$(ISO): $(ISO_DIR)/boot/$(KERNEL) $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) $(ISO_DIR) --modules="multiboot"

# ==========================
# Run QEMU
# ==========================
run: $(ISO)
	qemu-system-i386 -cdrom $(ISO) -no-reboot -d int,cpu_reset

# ==========================
# Clean
# ==========================
clean:
	rm -rf $(BUILD_DIR) $(KERNEL) $(ISO) $(ISO_DIR)

# ==========================
# Phony targets
# ==========================
.PHONY: all run debug clean
