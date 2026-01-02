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
    if (kstrcmp(cmd, "test") == 0) {
        // All test commands go here:
        // return has to be after every command because if there wasnt return it could lead to unexpected behavior such as executing the command
        // and event if it executes it goes deeper and prints that its Invalid Command even when it isnt
        return;
    }
    print("Invalid Command: ");
    print(cmd);
    printc('\n');
    return;
}

/*TODO
add more commands
make them separated from dispatcher in /commands/cmd_*.c to add some modularization and to prevent any bugs
and for easier debugging
commands todo today:
manpage and changelog which will print info about new versions
implement full/partial string.h lib add some fine touches to the OS and add customization along side with Hardcoded login root:root 
and maybe fake booting during start up and have atleast partial functioning RAMFS*/