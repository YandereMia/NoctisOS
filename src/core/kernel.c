#include <stdint.h>
#include "../../inc/core/terminal.h"
#include "../../inc/utils/kstrcmp.h"
void kernel_main(void) {
    if (kstrcmp("help", "help") == 0) {
        print("True\n");
        print("True\n");
    } else {
        print("False\n");
        print("False\n");
    }
    while(1);
}

