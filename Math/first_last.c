/*
Сравнивает числа и создает порядок
Example:
1 2 3 4
1 4 2 3
~~~~~~~
1 6 3 9
1 9 6 3
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(sizeof(int));
    if (arr == NULL) {
        printf("n/a\n");
    } else {
        int flag = 1, i = 0, elem = 0;
        char ch;
        do {
            if (scanf("%d%c", &elem, &ch) == 2 && (ch == ' ' || ch == '\n')) {
                if (i != 0) arr = realloc(arr, sizeof(int) * (i + 1));

                arr[i] = elem;
                i++;
            } else {
                flag = 0;
                printf("n/a");
            }
        } while (ch != '\n' && flag == 1);
        if (flag == 1 && i > 1) {
                int len = i / 2;
                for (int j = 0; j < len; j++) {
                    printf("%d ", arr[j]);
                    if (i % 2 == 0 && j == len - 1) {
                        printf("%d", arr[i - j - 1]);
                    } else {
                        printf("%d ", arr[i - j - 1]);
                    }
                }
                if (i % 2 == 1) printf("%d\n", arr[len]);
        } else {
            printf("%d\n", arr[0]);
        }
    }
    if (arr != NULL) free(arr);
    return 0;
}
