#ifndef _ASM_H_   /* Include guard */
#define _ASM_H_
#include <stdint.h>
#define enableInterrupts()  asm volatile ("sti")
void outb(uint16_t, uint8_t);
uint8_t inb(uint16_t port);

#endif