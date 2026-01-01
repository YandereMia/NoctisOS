#include <stdint.h>
#include <stdbool.h>
#include "../../inc/core/io.h"

#define INPUT_ENCODE_BUF 0x60

// jednoduché mapování XT scan kódů pro písmena a čísla
char scancode_map[128] = {
    0, 27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b', // 0x00-0x0f
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',    // 0x10-0x1c
    0, // kontrolní klávesy (LCTRL)
    'a','s','d','f','g','h','j','k','l',';','\'','`', 0,         // 0x1d-0x2a
    '\\','z','x','c','v','b','n','m',',','.','/', 0,             // 0x2b-0x35
    '*',0, ' ', 0,0,0,0,0,0,0,0,0,0,0,0,0                        // 0x36-0x45
};

// funkce pro čtení z portu 0x60
uint8_t keyboard_read_scancode() {
    while ((inb(0x64) & 1) == 0); // čekej, dokud není buffer plný
    return inb(INPUT_ENCODE_BUF);
}