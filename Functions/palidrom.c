/*
Нужно проверить является ли слово - палидромом
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* data = NULL;
    char sym = '\0';
    int index = 0, flag = 1;
    if ((data = (char*)malloc(sizeof(char*))) == NULL) exit(1);
    while(sym != '\n') {
        scanf("%c", &sym);
        data = (char*)realloc(data, sizeof(char*) + index);
        if (sym != '\n') {
            data[index] = sym;
            index++;
        }
    }
    if (data == NULL) {
        printf("NO\n");
    } else {
        for (int i = 0, j = index - 1; i < index; i++, j--)
            if (data[i] != data[j]) {
                flag = 0;
                break;
            }

        free(data);
        flag ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
