#include <stdint.h>
#include "../../inc/core/terminal.h"
#include "../../inc/utils/kstrcmp.h"
void kernel_main(void) {
    char cmd[256];
    while(1) {
        read(cmd, sizeof(cmd));
    }
}

