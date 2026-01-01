#ifndef TERMINAL_H
#define TERMINAL_H

void print(const char *s);
void printc(char c);
void read(char *buff, int max_len);
void clear_screen();
void banner();
#endif