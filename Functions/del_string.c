/*
Из второй строки удалить первую
s1 = one two one three
s2 = one
output: two  three
*/
#include <stdio.h>
#include <stdlib.h>

int find_index(char*, char*);
void output(char*, int, int);


int main() {
    if ((char *s1 = malloc(sizeof(char))) == NULL) exit(1);
    if ((char *s2 = malloc(sizeof(char))) == NULL) exit(1);
    char c;

    for (int i = 0; (c = getchar()) != '\n'; i++) {
        s1 = realloc(s1, i + sizeof(char));
        s1[i] = c;
    }
    for (int i = 0; (c = getchar()) != '\n'; i++) {
        s2 = realloc(s2, i + sizeof(char));
        s2[i] = c;
    }

    if (find_index(s1, s2) == -1) {
        printf("n/a\n");
        exit(1);
    }
    if (s1 != NULL) free(s1);
    if (s2 != NULL) free(s2);
    return 0;
}


int find_index(char* s1, char* s2) {
    int i_tmp = 0, s1_length = 0, s2_length = 0, j = 0, check = 0, flag = -1;

    for (int i = 0; s1[i]; i++) s1_length++;
    for (int i = 0; s2[i]; i++) s2_length++;

    for (int i = s1_length - 1; s1[i]; i--) {
        check = 0;
        i_tmp = i;
        if (s1[i] == s2[s2_length - 1]) {
            for (j = s2_length - 1; s2[j]; j--) {
                if (s1[i_tmp] == s2[j]) check++;
                i_tmp--;
            }
            if (s2_length == check) {
                output(s1, i, s2_length);
                flag = 0;
            }
        }
    }
    return flag;
}


void output(char *s1, int i, int s2_length) {
    printf("i = %d\nl = %d\n", i, s2_length);
    for (int j = 0; s1[j]; j++)
        if (j <= i - s2_length || j > i)
            printf("%c", s1[j]);
    printf("\n");
}
