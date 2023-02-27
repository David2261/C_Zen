#include <stdio.h>


/* Я думаю, это лучший способ показать стабильные абстракции.
 * Можно было использовать полиморфизм через 2 структуры, но это долго и тяжело. */
int main() {
    int a = 40;
    printf("It's a simple number %d with type integer.\n", a);
    int* ax = &a;
    *ax = 50;
    printf("It's a pointer to number %d\n", *ax);
    int** axx = &ax;
    **axx = 60;
    printf("It's a double pointer to number %d\n", **axx);
    return 0;
}

