#include <stdint.h>
#include "../../inc/core/terminal.h"
#include "../../inc/core/dispatcher.h"
#include "../../inc/core/login.h"
void kernel_main(void) {
    login();
    banner();
    char cmd[256];
    while(1) {
        print(username);
        print("@NoctisOS> ");
        read(cmd, sizeof(cmd));
        printc('\n');
        dispatcher(cmd);
    }
}