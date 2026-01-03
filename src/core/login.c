#include "../../inc/core/terminal.h"
#include "../../inc/utils/string.h"
char username[16];
char password[16];
void login() {
    for (int i = 0; i < 3; i++) {
        print("username> ");
        read(username, sizeof(username));
        if (kstrcmp(username, "root") == 0) {
            print("\npass> ");
            read(password, sizeof(password));
            if (kstrcmp(password, "root") == 0) {
                print("\nLogin passed\n");
                break;
            } else {
                print("\nLogin Failed!\n");
                continue;
            }
        } else {
            print("\nLogin Failed!\n");
            continue;
        }
    }
}

void changename() {
    print("change username to> ");
    read(username, sizeof(username));
    print("\nusername was successfully changed to ");
    print(username);
    printc('\n');
}