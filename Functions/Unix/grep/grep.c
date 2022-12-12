#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GET getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)
#define REG_EXT_NEW REG_EXTENDED | REG_NEWLINE
#define NO_FLAGS_L_V_C !flag.l && !flag.v && !flag.c

struct flags
{
    int c, e, f, h, i, l, n, o, v, s, many_files, c_counter, l_counter,
        n_counter;
};

struct grep_char
{
    size_t counter;
    char name[500][500];
};

void error_no_file_printer(const char *file_name);
void pattern_file_copy(const char *file_name);
void file_hook(const char *file_name);
void pattern_copy(const char *string);
void s21_grep(int argc, char **argv);
size_t flag_num_in_array(int c);
void file_printer(FILE *file);
void pattern_exe(char *str);
void flag_finder(int c);
void print_file_name();
void error_printer();
void printer_add();

struct flags flag = {0};
struct grep_char s21_pattern = {0};
struct grep_char s21_file = {0};

void s21_grep(int argc, char **argv)
{
    if (argc < 3)
        error_printer();
    for (int c = GET; c != -1; c = GET)
        flag_finder(c);
    if (!flag.e && !flag.f)
        pattern_copy(argv[optind++]);
    flag.many_files = argc - optind;
    while (optind < argc)
        file_hook(argv[optind++]);
}

void flag_finder(int c)
{
    if (c == '?')
        error_printer();
    *(&flag.c + flag_num_in_array(c)) = 1;
    if (c == 'f')
        pattern_file_copy(optarg);
    if (c == 'e')
        pattern_copy(optarg);
}

size_t flag_num_in_array(int c)
{
    size_t res = 0;
    for (const char *str = "cefhilnovs"; str[res] != (char)c; res++)
    {
    }
    return res;
}

void pattern_copy(const char *string)
{
    strcpy(s21_pattern.name[s21_pattern.counter++], string);
}

void pattern_file_copy(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file)
    {
        for (char c = getc(file); !feof(file);
             s21_pattern.counter++, c = getc(file))
        {
            size_t pos = 0;
            s21_pattern.name[s21_pattern.counter][pos] = c;
            for (; c != '\n' && !feof(file);
                 s21_pattern.name[s21_pattern.counter][pos++] = c, c = getc(file))
            {
            }
        }
        fclose(file);
    }
    else
    {
        error_no_file_printer(file_name);
        exit(0);
    }
}

void file_hook(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file)
    {
        strcpy(s21_file.name[s21_file.counter++], file_name);
        file_printer(file);
        fclose(file);
    }
    else if (!flag.s)
    {
        error_no_file_printer(file_name);
    }
}

void file_printer(FILE *file)
{
    char str[500] = "";
    flag.c_counter = flag.l_counter = flag.n_counter = 0;
    for (char c = getc(file); !feof(file); c = getc(file))
    {
        flag.n_counter++;
        size_t pos = 0;
        str[pos] = c;
        for (; c != '\n' && !feof(file);
             str[pos++] = c, c = getc(file))
        {
        }
        str[pos] = '\0';
        pattern_exe(str);
        if (flag.l_counter == 1)
            break;
    }
    printer_add();
}

void pattern_exe(char *str)
{
    size_t res = 0, first_file = 0, first_num = 0;
    regmatch_t pmatch[1] = {0};
    regex_t preg = {0};

    for (size_t current = 0; current < s21_pattern.counter; current++)
    {
        if (regcomp(&preg, s21_pattern.name[current],
                    flag.i ? REG_EXT_NEW | REG_ICASE : REG_EXT_NEW))
            continue;
        if (flag.o && NO_FLAGS_L_V_C)
        {
            while (!regexec(&preg, str, 1, pmatch, 0))
            {
                if (first_file++ == 0)
                    print_file_name();
                if (flag.n && first_num++ == 0)
                    printf("%d:", flag.n_counter);
                printf("%.*s\n", (int)(pmatch[0].rm_eo - pmatch[0].rm_so), str + pmatch[0].rm_so);
                str += pmatch[0].rm_eo;
            }
        }
        else if (regexec(&preg, str, 0, pmatch, 0) == flag.v)
        {
            res++;
        }
        regfree(&preg);
    }

    if (res == s21_pattern.counter || (res && !flag.v))
    {
        if (flag.c)
            flag.c_counter++;
        if (flag.l)
            flag.l_counter = 1;
        if (!flag.c && !flag.l)
        {
            print_file_name();
            if (flag.n)
                printf("%d:", flag.n_counter);
            printf("%s\n", str);
        }
    }
}

void printer_add()
{
    if (flag.o && NO_FLAGS_L_V_C)
        return;
    if (flag.c)
    {
        print_file_name();
        printf("%d\n", flag.c_counter);
    }
    if (flag.l && flag.l_counter)
        printf("%s\n", s21_file.name[s21_file.counter - 1]);
}

void print_file_name()
{
    if (flag.many_files > 1 && !flag.h)
        printf("%s:", s21_file.name[s21_file.counter - 1]);
}

void error_printer()
{
    system("clear");
    if (!flag.s)
        printf(
            ">\t Usually people know what they're doing, apparently this is not about you."
            "\n./s21_grep [-options] [\"pattern\"] [\"file.name\"]");
    exit(0);
}

void error_no_file_printer(const char *file_name)
{
    system("clear");
    printf("file: %s does not exist, and neither does the meaning of your life",
           file_name);
}

int main(int argc, char **argv)
{
    s21_grep(argc, argv);
    return 0;
}