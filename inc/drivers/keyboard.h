#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdint.h>
extern char scancode_map[128];
uint8_t keyboard_read_scancode();
#endif