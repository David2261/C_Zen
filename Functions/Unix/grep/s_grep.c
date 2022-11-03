#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "s_grep.h"


int main(int argc, char **argv) {
    struct Option opt;
    struct Option_2 opt_2;
    int FLAG = 0;
    char *template = (char*)malloc(sizeof(char));
    FILE* file;

    if (argc >= 3) {
        _get_args(argc, argv, file, template, &opt, &opt_2);
    } else {
        FLAG = 1;
    }
    if (FLAG == 0) {
        if (*template == NULL) {
            FLAG = 1;
            *template = malloc(sizeof(char) * (strlen(*file) + 1));
            if (*template != NULL) {
                strcpy(*template, *file);
                FLAG = 0;
            }
        }
        int count_file = _get_count_files(file) - flag_e_f_does_not_exist;
        for (int i = flag_e_f_does_not_exist; file[i] && error == SUCCESS; i++)
            _grep(&flags, file[i], template, count_file);
    }

    for (int i = 0; file[i]; i++)
        free(file[i]);
    for (int i = 0; template[i]; i++)
        free(template[i]);
    return FLAG;
}


void _grep(struct Option *opt, struct Option_2 *opt_2, char *file_name, char *template[], int count_file) {
    FILE *file = fopen(file_name, "r");
    if (file) {
        char *__linep = NULL;
        int count_matched_lines = 0;
        int count_line = 0;
        size_t __linecapp = 0;

        char *matches[BUFF] = {NULL};
        while (getline(&__linep, &__linecapp, file) > 0) {
            count_line++;
            if (_template_matching(__linep, template, matches, flags)) {
                count_matched_lines++;
                if (!flags->c && !flags->l) {
                    _handle_header(file_name, count_file, flags);
                    _handle_flag_n(count_line, flags);
                    if (flags->o && !flags->v) { //&& !flags->v
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
        // flag->c
        _handle_header_flag_c(flags, file_name, count_file);
        // flag->count_mutched_line
        _handle_flag_c(flags, count_matched_lines);
        // flag->l list files
        _handle_flag_l(flags, file_name, count_matched_lines);
        free(__linep);
        fclose(file);
    } else if (!flags->s) {
        sprintf(stderr, "grep: [%s] -- No such file or directory!\n", file_name);
    }
}

int _template_matching(const char *const linep, char *template[], char *matches[], const struct Option *opt, struct Option_2 *opt_2) {
    int index = 0;
    for (int i = 0; template[i]; i++) {
        regex_t regex;
        if (flags->i)
            regcomp(&regex, template[i], REG_ICASE);
        else
            regcomp(&regex, template[i], REG_EXTENDED);

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
    return flags->v ? !index : index;
}

void _handle_header(char *file_name, int count_file, struct Option *opt, struct Option_2 *opt_2) {
    if (!flags->c && !flags->h && count_file > 1)
        printf("%s:", file_name);
}

void _handle_flag_n(int count_line, struct Option *opt, struct Option_2 *opt_2) {
    if (flags->n)
        printf("%d:", count_line);
}

void _handle_flag_c(struct Option *opt, struct Option_2 *opt_2, int count_matched_lines) {
    if (flags->c) {
        printf("%d\n", flags->l ? count_matched_lines > 0 : count_matched_lines);
    }
}

void _handle_flag_l(struct Option *opt, struct Option_2 *opt_2, char *file_name, int count_matched_lines) {
    if (flags->l && count_matched_lines) {
        printf("%s\n", file_name);
    }
}

int _get_args(int argc, char *argv[], char *file_name[], char *template[], struct Option *opt, struct Option_2 *opt_2) {
    int error = SUCCESS;
    int template_ = 0;
    int file_ = 0;
    for (int i = 1; i < argc; i++) {
        if (_get_flags(argv[i], flags)) {
            if (_check_flags_exist(argv[i])) {
                error = FLAG_DOES_NOT_EXIST;
                break;
            }
            if ((flags->e || flags->f) && !argv[i]) {
                error = FLAG_DOES_NOT_EXIST;
                break;
            }
            if (flags->e) {
                // Сдвигаем инкрмент на еще +1, чтобы взять уже файл.
                i++;
                template[template_] = malloc(sizeof(char) * (strlen(argv[i] + 1)));
                if (template[template_] == NULL) {
                    error = MALLOC_ERROR;
                    break;
                }
                strcpy(template[template_], argv[i]);
                ++template_;
            } else if (flags->f) {
                i++;
                if ((error = _handle_flag_f(argv[i], template, &template_)) != SUCCESS) { break; }
            }
            _reset_flag_e_and_f(flags);
        } else {
            file_name[file_] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
            if (file_name[file_] == NULL) {
                error = MALLOC_ERROR;
                break;
            }
            strcpy(file_name[file_], argv[i]);
            ++file_;
        }
    }
    template[template_] = NULL;
    file_name[file_] = NULL;
    return error;
}

int _handle_flag_f(char *file_name, char *templates[], int *index) {

    int error = SUCCESS;
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("NO FILE");
        error = FILE_DOES_NOT_EXIST;
    } else {
        char *template = NULL;
        size_t __linep = 0;
        ssize_t __linep_length = 0;
        while ((__linep_length = getline(&template, &__linep, file)) > 0) {
            templates[*index] = malloc(sizeof(char) * (__linep_length + 1));
            if (templates[*index] == NULL) {
                error = MALLOC_ERROR;
                break;
            }
            strcpy(templates[*index], template);
            templates[*index][strcspn(templates[*index], "\r\n")] = '\0';
            // Если файл пустой с паттернами, то выведем все
            if (!strlen(templates[*index])) {
                templates[*index][0] = '.';
            }
            (*index)++;
        }

        fclose(file);
        free(template);
    }
    return error;
}

int _get_flags(char *argv, struct Option *opt, struct Option_2 *opt_2) {
    if (argv[0] == '-') {
        for (int i = 1; argv[i]; i++) {
            // if (strlen(argv) == 1 || strlen(argv) != strspn(argv, "-eivclnhsfo")) error = 1;
            if (opt.flag_e != 1) opt.flag_e = checker(argv[i], 'e');
            if (strchr(argv, 'i')) flags->i = 1;
            if (strchr(argv, 'v')) flags->v = 1;
            if (strchr(argv, 'c')) flags->c = 1;
            if (strchr(argv, 'l')) flags->l = 1;
            if (strchr(argv, 'n')) flags->n = 1;
            if (strchr(argv, 'h')) flags->h = 1;
            if (strchr(argv, 's')) flags->s = 1;
            if (strchr(argv, 'f')) flags->f = 1;
            if (strchr(argv, 'o')) flags->o = 1;
        }
    }
    return 0;
}

void _handle_header_flag_c(struct Option *opt, struct Option_2 *opt_2, char *file_name, int count_file) {
    if (flags->c && !flags->h && count_file > 1)
        printf("%s:", file_name);
}

void _reset_flag_e_and_f(struct Option *opt, struct Option_2 *opt_2) {
    flags->e = 0;
    flags->f = 0;
}

int _get_count_files(char *file_name[]) {
    int count = 0;
    while (*file_name++)
        ++count;
    return count;
}

int _check_flags_exist(char *argv) {
    int error = 0;
    for (int i = 1; argv[i]; i++)
        if (strlen(argv) != strspn(argv, "-eivclnhsfo"))
            error = 1;
    return error;
}