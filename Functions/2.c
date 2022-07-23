#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char*);
int main() {
    int remainder = 0, m = 1, a = 0;
    for (int i = 999; i >= 100; i--)
        for (int j = 999; j >= 100; j--) {
            a = i * j;
            int f = a;

            while (f == f / 10) m++;

            char* b = malloc(m * sizeof(b));

            while (a != 0) {
                remainder = a % 10;
                b[m-1] = remainder + '0';
                a = a / 10;
                if (m >= 0) m--;
            }

            if (check(b)) {
                printf("%s\n", b);
                exit(1);
            }
        }
}

int check(char *str) {
    int result = 0, l = 0, h = strlen(str) - 1;

    // Продолжает сравнивать символы, пока они равны
    while (h > l)
        if (str[l++] != str[h--])
            return 0;
    result = 1;
    return result;
}
