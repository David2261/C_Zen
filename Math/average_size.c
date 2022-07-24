/*
Описать структуру человек: Имя (строка), Фамилия (строка), рост (целое положительное число).
Example:
1
Bulat Nasyrov 180
Bulat Nasyrov 180
str = Bulat
name = Bulat
Nasyrov : 180
*/

#include <stdio.h>
#include <stdlib.h>

int strcmp21 (char*, char*);

struct Human {
    char Name[100];
    char Surname[100];
    double size;
};

int main() {
    int N = 0;
    if (scanf("%d", &N) != 1 || N < 1) {
        printf("n/a\n");
        return 1;
    }
    struct Human arr[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%s", arr[i].Name);
        scanf("%s", arr[i].Surname);
        if (scanf("%lf", &arr[i].size) != 1 || arr[i].size < 1) {
            printf("n/a\n");
            return 1;
        }
    }
    
    char name[100];
    scanf("%s", name);
    
    printf("str = %s\nname = %s\n", arr[0].Name, name);
    
    int count = 0;
    double sum = 0;
    
    for (int i = 0; i < N; i++) {
        if (strcmp21(name, arr[i].Name) == 0) {
            count++;
            sum += arr[i].size * 1.0;
            printf("%s, ", arr[i].Surname);
        }
    }
    printf("\b\b");
    printf(" : %0.lf\n", (sum / count));
    
    return 0;
}

int strcmp21(char* a, char* b) {
    char c1, c2;
    while (1) {
        c1 = *a++;
        c2 = *b++;
        if (c1 != c2) {
            return c1 < c2 ? -1 : 1;
        }
        if (!c1) break;
    }
    return 0;
}
