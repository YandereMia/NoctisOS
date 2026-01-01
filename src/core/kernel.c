#include <stdint.h>
#include "../../inc/core/terminal.h"

void kernel_main(void) {
    char cmd[256];
    print("Welcome To My NoctisOS this is just a test if this func is working or not :D");
    read(cmd, sizeof(cmd));
    while(1);
}

