#include "s_grep.h"

int main(int argc, char *argv[]) {
    struct Option_2 opt;
    int FLAG = 0, flag_e_f = 0;
    char *path = NULL;
    char *pattern = NULL;


    if (argc >= 3)
        _get_args(argc, argv, path, pattern, &opt);
    else
        FLAG = 1;

    if (!FLAG) {
        if (*pattern == NULL) {
            flag_e_f = 1;
            *pattern = malloc(sizeof(char) * (strlen(*path) + 1));
            if (*pattern == NULL) {
                FLAG = 1;
            } else {
                strcpy(*pattern, *path);
            }
        }

        int count_file = _get_count_files(path) - flag_e_f;
        // Можно добавить остановку цикла, если флаг = 1
        for (int i = flag_e_f; path[i] && !FLAG; i++) _grep(&opt, path[i], pattern, count_file);
    }
    for (int i = 0; path[i]; i++)
        free(path[i]);
    for (int i = 0; pattern[i]; i++)
        free(pattern[i]);

    if (FLAG == 1) printf("n/a");

    return FLAG;
}


int _get_count_files(char *file_name[]) {
    int count = 0;
    while (*file_name++)
        ++count;
    return count;
}



void _grep(struct Option_2 opt, char *path, char *pattern[], int count_file) {
    FILE *file = fopen(path, "r");
    if (file) {
        char *__linep = NULL;
        int count_matched_lines = 0;
        int count_line = 0;
        size_t __linecapp = 0;

        char *matches[BUFF] = {NULL};
        while (getline(&__linep, &__linecapp, file) > 0) {
            count_line++;
            if (_pattern_matching(__linep, pattern, matches, opt)) {
                count_matched_lines++;
                if (!opt.flag_c && !opt.flag_l) {
                    if (!opt.flag_c && !opt.flag_h && count_file > 1) printf("%s:", path);
                    if (opt.flag_n) printf("%d:", count_line);
                    if (opt.flag_o && !opt.flag_v) {
                        for (int j = 0; matches[j]; j++) {
                            printf("%s\n", matches[j]);
                        }
                    } else {
                        if (__linep[strlen(__linep) - 1] == '\n') {
                            printf("%s", __linep);
                        } else {
                            printf("%s\n", __linep);
                        }
                    }
                }
            }
            for (int j = 0; matches[j]; j++)
                free(matches[j]);
        }
        if (opt.flag_c && !opt.flag_h && count_file > 1) printf("%s:", path);
        if (opt.flag_c) printf("%d\n", opt.flag_l ? count_matched_lines > 0 : count_matched_lines);
        if (opt.flag_l && count_matched_lines) printf("%s\n", path);
        free(__linep);
        fclose(file);
    } else if (!opt.flag_s) {
        printf("n/a");
    }
}

int _pattern_matching(const char *const linep, char *pattern[], char *matches[], const struct Option_2 opt) {
    int index = 0;
    for (int i = 0; pattern[i]; i++) {
        regex_t regex;
        if (flags->i)
            regcomp(&regex, pattern[i], REG_ICASE);
        else
            regcomp(&regex, pattern[i], REG_EXTENDED);

        regmatch_t match;
        size_t linep_length = strlen(linep);
        size_t reg_offset = 0;

        for (int reg; (reg = regexec(&regex, linep + reg_offset, 1, &match, 0)) == 0; index++) {
            int length = match.rm_eo - match.rm_so;

            matches[index] = malloc(length + 1);
            memcpy(matches[index], linep + match.rm_so + reg_offset, length);
            matches[index][length] = '\0';
            reg_offset += match.rm_eo;
            if (reg_offset > linep_length) break;
        }
        matches[index] = NULL;
        regfree(&regex);
    }
    return opt.flag_v ? !index : index;
}


int _get_args(int argc, char *argv[], char *path[], char *pattern[], struct Option_2 opt) {
    int FLAG = 0;
    int pattern_ = 0;
    int file_ = 0;
    for (int i = 1; i < argc; i++) {
        if (_get_flags(argv[i], opt)) {
            for (int i = 1; argv[i]; i++)
                if (strlen(argv) != strspn(argv, "-eivclnhsfo")) {
                    FLAG = 1;
                    break;
                }
            if ((opt.flag_e || opt.flag_f) && !argv[i]) {
                FLAG = 0;
                break;
            }
            if (opt.flag_e) {
                // Сдвигаем инкрмент на еще +1, чтобы взять уже файл.
                i++;
                pattern[pattern_] = malloc(sizeof(char) * (strlen(argv[i] + 1)));
                if (pattern[pattern_] == NULL) {
                    FLAG = 1;
                    break;
                }
                strcpy(pattern[pattern_], argv[i]);
                ++pattern_;
            } else if (opt.flag_f) {
                i++;
                if ((FLAG = _handle_flag_f(argv[i], pattern, &pattern_)) != 0) { break; }
            }
            opt.flag_e = 0;
            opt.flag_f = 0;
        } else {
            path[file_] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
            if (path[file_] == NULL) {
                FLAG = 1;
                break;
            }
            strcpy(path[file_], argv[i]);
            ++file_;
        }
    }
    pattern[pattern_] = NULL;
    path[file_] = NULL;
    return FLAG;
}

int _handle_flag_f(char *path, char *patterns[], int *index) {

    int FLAG = SUCCESS;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("n/a");
        FLAG = 1;
    } else {
        char *pattern = NULL;
        size_t __linep = 0;
        ssize_t __linep_length = 0;
        while ((__linep_length = getline(&pattern, &__linep, file)) > 0) {
            patterns[*index] = malloc(sizeof(char) * (__linep_length + 1));
            if (patterns[*index] == NULL) {
                error = MALLOC_ERROR;
                break;
            }
            strcpy(patterns[*index], pattern);
            patterns[*index][strcspn(patterns[*index], "\r\n")] = '\0';
            // Если файл пустой с паттернами, то выведем все
            if (!strlen(patterns[*index])) {
                patterns[*index][0] = '.';
            }
            (*index)++;
        }

        fclose(file);
        free(pattern);
    }
    return error;
}

int _get_flags(char *argv, struct Option_2 opt) {
    int parametr = 0;
    if (argv[0] == '-') {
        for (int i = 1; argv[i]; i++) {
            if (opt.flag_e != 1) opt.flag_e = checker(argv, 'e');
            if (opt.flag_i != 1) opt.flag_i = checker(argv, 'i');
            if (opt.flag_v != 1) opt.flag_v = checker(argv, 'v');
            if (opt.flag_c != 1) opt.flag_c = checker(argv, 'c');
            if (opt.flag_l != 1) opt.flag_l = checker(argv, 'l');
            if (opt.flag_n != 1) opt.flag_n = checker(argv, 'n');
            if (opt.flag_h != 1) opt.flag_h = checker(argv, 'h');
            if (opt.flag_s != 1) opt.flag_s = checker(argv, 's');
            if (opt.flag_f != 1) opt.flag_f = checker(argv, 's');
            if (opt.flag_o != 1) opt.flag_o = checker(argv, 'o');
        }
        parametr = 1;
    }
    return parametr;
}