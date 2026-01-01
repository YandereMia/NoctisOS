#include <stdint.h>
#include <stdbool.h>
#include "../../inc/core/io.h"

#define INPUT_ENCODE_BUF 0x60

char scancode_map[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,
    '\\','z','x','c','v','b','n','m',',','.','/', 0,
    '*',0, ' ', 0,0,0,0,0,0,0,0,0,0,0,0,0
};


uint8_t keyboard_read_scancode() {
    while ((inb(0x64) & 1) == 0);
    return inb(INPUT_ENCODE_BUF);
}