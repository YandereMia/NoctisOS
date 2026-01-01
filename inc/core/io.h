#ifndef IO_H
#define IO_H
#include <stdint.h>
#define enableInterrupts()  asm volatile ("sti")
void outb(uint16_t, uint8_t);
uint8_t inb(uint16_t port);

#endif