#include <stdint.h>
#include "../../inc/core/terminal.h"
void dispatcher(const char *cmd);

void kernel_main(void) {
    char cmd[256];
    while(1) {
        print("NoctisOS> ");
        read(cmd, sizeof(cmd));
        printc('\n');
        dispatcher(cmd);
    }
}

// Test dispatcher for now tmrw gonna add it to /src/core/dispatcher.c
// and add more commands... hopefully :D
#include "../../inc/utils/kstrcmp.h"

void dispatcher(const char *cmd) {
    if (kstrcmp(cmd, "help") == 0) {
        print("help - shows this page\n");
        return;
    }
    print("Invalid Command: ");
    print(cmd);
    printc('\n');
}