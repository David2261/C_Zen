/*
Input: 159, 120, -123
(развернуть)
Output: 951, 021, -321
*/
#include <stdio.h>


int main() {
    int num = 0;
    if (scanf("%d", &num) != 1) {
        printf("n/a");
        return 1;
    }
    // Записываем каждое число
    int f_num = num / 100;
    int s_num = num / 10 % 10;
    int t_num = num % 10;
    // Обратный результат
    int res = t_num * 100 + s_num * 10 + f_num;
    printf("%.3d", res);
    return 0;
}

