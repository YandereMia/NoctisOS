#include <stdint.h>
#include "../../inc/core/terminal.h"
#include "../../inc/core/dispatcher.h"

void kernel_main(void) {
    char cmd[256];
    while(1) {
        print("NoctisOS> ");
        read(cmd, sizeof(cmd));
        printc('\n');
        dispatcher(cmd);
    }
}