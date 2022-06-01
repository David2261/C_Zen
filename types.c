// для windows

#include <stdio.h>
#include <conio.h>
// Библиотека для использования булевых выражений
#include <stdbool.h>

int main() {

    // Булевые значения
    bool isHasCar = true;

    // Переменная
    int u;
    short x = 5, y = 10, res;

    // Числа от -32 тыс до 32 тыс
    short s = 500;

    // Числа только положительные от 0 до 64 тыс
    unsigned short a = 5;

    // Числа от 0 до 4 млн
    unsigned int a1 = 6;

    // Числа больше
    long a2 = 5;
    unsigned long a3 = 4;

    // Дробные числа
    const float A6 = 4.5f;

    // Дробные числа для чисел с большим количеством знаков после запятой
    double a7 = 5.6327467832648729647862f;
    // long double

    // Это символ - НЕ ЧИСЛО
    char sym = "7";


    x *= 5;
    x--;

    res = x + y;

    // d - Число

    printf("Variable: %d + %d = %d\n", x, y, res);

    float z = 5.5f, i = 6.67f, result;

    result = z / i;
    printf("Result: %.2f\n", result);

    char s1 = 'S';

    printf("%c\n", s1);

    float o;
    scanf("%f", &o);
    printf("%f\n", o);

    return 0;
}
