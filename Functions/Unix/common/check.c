#include "main.h"

// Проверяет на наличие нашего флага в списке
int checker(char* flags, char flag) {
    int tmp = 0;
    for (int i = 0; (unsigned)i < strlen(flags); i++) {
        if (flags[i] == flag) {
            tmp = 1;
            break;
        }
    }
    return tmp;
}


