#include <stdint.h>
#include "../../inc/utils/kstrlen.h"
#include "../../inc/drivers/keyboard.h"
#include "../../inc/core/terminal.h"
volatile uint16_t* vga = (uint16_t*)0xB8000;

int cursor_x = 0;
int cursor_y = 0;

void print(const char *s) {
    int len = kstrlen(s);
    for (int i = 0; i < len; i++) {
        printc(s[i]);
    }
}

void printc(char c) {
    if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    } else {
        int pos = cursor_y * 80 + cursor_x;
        vga[pos] = (uint16_t)c | (0x0F << 8);
        cursor_x++;
    }

    if (cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
    }

    if (cursor_y >= 25) {
        for (int y = 1; y < 25; y++) {
            for (int x = 0; x < 80; x++) {
                vga[(y-1)*80 + x] = vga[y*80 + x];
            }
        }

        for (int x = 0; x < 80; x++) {
            vga[24*80 + x] = ' ' | (0x0F << 8);
        }

        cursor_y = 24;
    }
}

void read(char *buff, int max_len) {
    int i = 0;
    while (i < max_len - 1) {
        uint8_t scancode = keyboard_read_scancode();

        if (scancode & 0x80) continue;

        char c = scancode_map[scancode];
        if (c == '\n') {
            buff[i] = '\0';
            return;
        }

        if (c) {
            buff[i++] = c;
            printc(c);
        }
    }
    buff[i] = '\0';
}