#include <stdio.h>
#include <stdlib.h>

/*
Input: A = 3 B = 7 C = 6
Нужно проверить, на выполнение этого условия a < b < c
Если True = return 0, False = 1
* Нельзя использовать if .. else
Output: 1
*/
int main() {
    int a, b, c;
    char e;
    if (scanf("%d %d %d", &a, &b, &c) != 3 || ((e = getchar() != ' ' || e != '\n'))) {
        printf("n/a");
        return 1;
    }
    printf("%d", (a < b && b < c));
    return 0;
}