#include <stdio.h>

int user1(int);
int user2(int);


int main() {
    int mass = 23;
    printf("Some data 1: %d, 2: %d \n", user1(mass), user2(mass));
    return 0;
}


int user1(int mass) {
    return mass * 34;
}

int user2(int mass) {
    return mass * 23;
}


