#include <stdio.h>

int year();
int month();

int main() {
    int y = year();
    int m = month();
    printf("Born in %d year and %d month\n", y, m);
    return 0;
}

int year() {
    return 2003;
}

int month() {
    return 8;
}

