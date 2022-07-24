/*
Создание спирали из матрицы
Example:
3
1    2    3
8    9    4
7    6    5
*/
#include <stdio.h>
#include <stdlib.h>

int input(int*);
int** alloc_mtx(int);
int free_mtx(int**, int);
int output(int**, int);
int spiral(int**, int);

int main() {
    int n = 0, **arr = NULL;
    if (input(&n) || (arr=alloc_mtx(n)) == NULL) {
        printf("код не работает\n");
    } else {
        spiral(arr, n);
        output(arr, n);
    }
    if (arr != NULL) {
        free_mtx(arr, n);
    }
    return 0;
}

int input(int *n) {
    char c;
    int stat = 1;
    // Создается цикл, в котором проверяется последний элемент
    if(scanf("%d", n) == 1 && (((c=getchar()) == ' ') || c == '\n')) {
        stat = 0;
    }
    // Если массив <= 0
    if (*n < 1) {
        stat = 1;
    }
    return stat;
}

/* Функция определение памяти */
int** alloc_mtx(int n) {
    // Горизонталь
    int **arr = (int**)malloc(n*sizeof(int*));

    // Вертикаль
    for (int i = 0; i < n; i++)
        arr[i] = (int*)malloc(n*sizeof(int));
    return arr;
}

/* Функция освобождения памяти */
int free_mtx(int **arr, int n) {
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}

int output(int **arr, int n) {
    // Вывод по горизонтали
    for (int i = 0; i < n; i++) {
        // Вывод по вертикали
        for (int j = 0; j < n; j++) {
            if (j != n - 1) {
                printf("%4.d ", arr[i][j]);
            } else {
                printf("%4.d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}

/* Функция создания спирали */
int spiral(int **arr, int n) {
    int c = 0;
    int b = 0;
    
    // Для отлова бага на матрицу из 3 элементов
    if (n <= 3) {
        b = 1;
    } else {
        b = 2;
    }
    if (n != 1) {
        // Вывод по горизонтали
        for (int a = 0; a < n-b; a++) {
            // Отвечает за верхюю сторону
            for (int j = 0+a; j < n-a; j++) {
                c++;
                arr[a][j] = c;
            }
            // Отвечает за правую сторону
            for (int i = 1+a; i < n - a; i++) {
                c++;
                arr[i][n-1-a] = c;
            }
            // Отвечает за нижний уровень матрицы
            for (int j = n-2-a; j+1 > a; j--) {
                c++;
                arr[n-1-a][j] = c;
            }
            // Отвечает за левую сторону
            for (int i = n-2-a; i > a; i--) {
                c++;
                arr[i][a] = c;
            }
        }
    } else {
        arr[0][0] = 1;
    }
    return 0;
}
