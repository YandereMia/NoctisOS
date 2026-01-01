#include "../../inc/utils/kstrcmp.h"
#include "../../inc/core/terminal.h"
#include <stdint.h>

void dispatcher(const char *cmd) {
    if (kstrcmp(cmd, "help") == 0) {
        print("help - shows this page   |   banner - show motd\n");
        print("clear - clears screen\n");
        return;
    }
    if (kstrcmp(cmd, "clear") == 0) {
        clear_screen();
        return;
    }
    if (kstrcmp(cmd, "banner") == 0) {
        banner();
        return;
    }
    print("Invalid Command: ");
    print(cmd);
    printc('\n');
    return;
}