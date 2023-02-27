#include "ocp.h"

int main() {
    int *data = (int*)malloc(sizeof(int*)*4);
    for (int i = 0; i < 4; i++) data[i] = calculation(i);
    output(data);
    return 0;
}

int calculation(int x) {
    return x * 16;
}

void output(int *data) {
    for (int i = 0; i < 4; i++) printf("%d\n", data[i]);
}


