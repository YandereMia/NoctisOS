#include <stdint.h>
#include "../../inc/utils/kstrlen.h"
#include "../../inc/drivers/keyboard.h"
volatile uint16_t* vga = (uint16_t*)0xB8000;

void print(char *src[]) {
    int len = kstrlen(*src);
    for (int i = 0; i < len; i++) {
        vga[i] = (uint8_t) *src[i] | (0x0F << 8);
    }
}

void printc(char src) {
    vga[1] = (uint8_t) src | (0x0F << 8);
}

void read(char *buff, int max_len) {
    int i = 0;
    while (i < max_len - 1) {
        uint8_t scancode = keyboard_read_scancode();

        // ignoruj break kódy (key release)
        if (scancode & 0x80) continue;

        char c = scancode_map[scancode];
        if (c == '\n') {  // Enter → ukončení čtení
            buff[i] = '\0';
            return;
        }

        if (c) {
            buff[i++] = c;
            printc(c); // zobraz znak na obrazovku
        }
    }
    buff[i] = '\0';
}