#include <stdio.h>
#include <string.h>
#include "s_cat.h"

int main(int argc, char **argv) {
    struct Option opt;
    int i = 0, FLAG = 0;
    if (1 < argc) {
        // Проверяем на параметры
        while (i < argc) {
            if (argv[i][0] == '-' && argv[i][1] != '-') {
                if (opt.flag_b != 1) opt.flag_b = checker(argv[i], 'b');
                if (opt.flag_e != 1) opt.flag_e = checker(argv[i], 'e');
                if (opt.flag_n != 1) opt.flag_n = checker(argv[i], 'n');
                if (opt.flag_s != 1) opt.flag_s = checker(argv[i], 's');
                if (opt.flag_t != 1) opt.flag_t = checker(argv[i], 't');
                if (opt.flag_T != 1) opt.flag_T = checker(argv[i], 'T');
                if (opt.flag_E != 1) opt.flag_E = checker(argv[i], 'E');
            }
            if (argv[i][0] == '-' && argv[i][1] == '-') {
                if (strcmp(&argv[i][0], "--number") == 0) opt.flag_n = 1;
                if (strcmp(&argv[i][0], "--number-nonblank") == 0) opt.flag_b = 1;
                if (strcmp(&argv[i][0], "--squeeze-blank") == 0) opt.flag_s = 1;
            }
            i++;
        }

        FLAG = read_file(argv, &opt);
    } else {
        printf("n/a");
    }

    return FLAG;
}

int read_file(char** argv, struct Option *opt) {
    FILE* file;
    argv++;
    int result = 1, FLAG = 0;
    while (*argv) {
        if (*argv[0] == '-') {
            argv++;
            FLAG = 1;
        } else {
            if ((file = fopen(*argv, "r")) == NULL) {
                argv++;
            } else {
                result = cat(*opt, file, result);
                argv++;
            }
            FLAG = 0;
        }
    }
    pclose(file);
    return FLAG;
}

// Считывание файла
int cat(struct Option opt, FILE* file, int count) {
    int now, prev = '\n';
    int temp = 0;
    while ((now = getc(file)) != EOF) {
        // Просто перенос
        if (opt.flag_s) {
            if (now == '\n') temp++;
            if (now != '\n') temp = 0;
        }
        // 1, 2, 3
        if (opt.flag_b && temp < 3) {
            if ((prev == '\n' && !(now == '\n')) || count == 1) {
                printf("%6d\t", count);
                count++;
            }
        }
        // 1, 2, 3 также и пустые строки
        if (opt.flag_n && !opt.flag_b && temp < 3) {
            if (prev == '\n' || count == 1) {
                printf("%6d\t", count);
                count++;
            }
        }
        // ...$
        if (opt.flag_E || (opt.flag_e && temp < 3)) {
            if ((opt.flag_t || opt.flag_e) && now >= 0 && now < 32 && now != '\n' && now != '\t') {
                printf("^%c", 64 + now);
            } else if ((opt.flag_t || opt.flag_T) && now == '\t') {
                printf("^I");
            } else if (now != '\n') {
                printf("%c", now);
            }
            if (now == '\n') {
                printf("$\n");
            } else if (now != '\n') {
                temp = 0;
            }
        } else if (opt.flag_T || (opt.flag_t && temp < 3)) {
            // Просто перенос
            if (!opt.flag_e && opt.flag_t && now >= 0 && now < 32 && now != '\n' && now != '\t') {
                printf("^%c", 64 + now);
            } else if (now != '\t' && now != '\n') {
                printf("%c", now);
            } else if (!opt.flag_e && !opt.flag_E && now == '\n') {
                printf("\n");
            }
            if (now == '\t') {
                printf("^I");
            }
            if (now != '\n') temp = 0;
        } else {
            // ...$ также и пустые строки
            if (!((opt.flag_e || opt.flag_E) && now == '\n') && temp < 3) {
                putchar(now);
            }
        }
        prev = now;
    }
    return count;
}
