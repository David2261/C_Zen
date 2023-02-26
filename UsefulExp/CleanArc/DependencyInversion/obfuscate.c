#include  "obfuscate.h"

int main() {
    HighLevel();
    return 0;
}

void HighLevel() {
    printf("It's  a high level void function\n");
    MiddleLevel();
}

void MiddleLevel() {
    printf("It's a middle level void function\n");
    LowLevel();
    LowSecondLevel();
}

void LowLevel() {
    printf("It's a first low level void function\n");
}

void LowSecondLevel() {
    printf("It's a second low level void function\n");
}

