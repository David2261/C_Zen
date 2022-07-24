/*
Вывод произведения матриц, ввиде таблицы
Вход:
2
1 2
3 4
5 6
7 8
Выход:
19 22
43 50
*/
#include <stdio.h>
#include <stdlib.h>

int **matrix(int);
void input(int**, int, int*);
void multiply(int**, int**, int, int**);
void output(int**, int);
void free_malloc(int**, int);

int main() {
    int size = 0;
    char c;
    int flag = 0;
    if (scanf("%d", &size) != 1 || (c = getchar()) != '\n' || size < 1) {
        flag = 1;
        printf("n/a\n");
    } else {
        int **matrix1 = matrix(size);
        int **matrix2 = matrix(size);
        int **matrix_res = matrix(size);

        if (NULL == matrix1 || NULL == matrix2 || NULL == matrix_res) {
            flag = 1;
            printf ("n/a\n");
        } else {
            input(matrix1, size, &flag);
            input(matrix2, size, &flag);

            if (flag != 0) {
                printf("n/a\n");
            } else {
                multiply(matrix1, matrix2, size, matrix_res);
                output(matrix_res, size);
            }
        }
        if (flag != 1) {
            free_malloc(matrix1, size);
            free_malloc(matrix2, size);
            free_malloc(matrix_res, size);
        }
    }
    return flag;
}

int **matrix(int size) {
    int **m = NULL;
    if ((m = malloc(size * sizeof(int*))) == NULL) exit(1);

    for (int i = 0; i < size; i++) {
        m[i] = malloc(size * sizeof(int));
    }
    return m;
}

/* Функция умножения */
void multiply(int **matrix1, int **matrix2, int size, int **matrix_res) {
    int t = 0;
    while (t < size) {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                matrix_res[i][j] = matrix_res[i][j] + matrix1[i][t] * matrix2[t][j];
        t++;
    }
}

void input(int **array, int size, int *flag) {
    char c;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (scanf("%d", &array[i][j]) == 1 && (c = getchar()) == '\n');
            else *flag = 21;
        }
    }
}

void output(int** matrix, int size) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        for (j = 0; j < size; j++)
            printf("%d ", matrix[i][j]);
        printf("\b");
        if (i != size - 1 && j != size - 1) printf("\n");
    }
}

/* Освобождение памяти */
void free_malloc(int **matrix, int size) {
    for (int i = 0; i < size; i++) free(matrix[i]);
    free(matrix);
}
