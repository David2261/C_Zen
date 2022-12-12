#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int b; // Нумеровать строки, как и при указании опции -n, но пустые строки не нумеруются.
    int e; // Выдавать в конце каждой строки символ $ (перед символом новой строки).
    int E; // Тоже самое, но без -v
    int v; // Выдавать непечатные символы. Управляющие символы ASCII.
    int n; // Выдовать порядковый номер строки каждой строки.
    int s; // Не выдавать сообщений о не существующих файлах.
    int t; // Выдавать символы табуляции как ^I, а символы прогона страницы - как ^L.
    int T; // Тоже самое, но без -v
} Flags;

// Массив не печатных символов который не может быть изменен.
static const char *special_symbol[255] = {
    [0] = "^@", [1] = "^A", [2] = "^B", [3] = "^C", [4] = "^D", [5] = "^E", [6] = "^F", [7] = "^G", [8] = "^H", [9] = "^I", [10] = "\n", [11] = "^K", [12] = "^L", [13] = "^M", [14] = "^N", [15] = "^O", [16] = "^P", [17] = "^Q", [18] = "^R", [19] = "^S", [20] = "^T", [21] = "^U", [22] = "^V", [23] = "^W", [24] = "^X", [25] = "^Y", [26] = "^Z", [27] = "^[", [28] = "^\\", [29] = "^]", [30] = "^^", [31] = "^_", [32] = " ", [33] = "!", [34] = "\"", [35] = "#", [36] = "$", [37] = "%", [38] = "&", [39] = "'", [40] = "(", [41] = ")", [42] = "*", [43] = "+", [44] = ",", [45] = "-", [46] = ".", [47] = "/", [48] = "0", [49] = "1", [50] = "2", [51] = "3", [52] = "4", [53] = "5", [54] = "6", [55] = "7", [56] = "8", [57] = "9", [58] = ":", [59] = ";", [60] = "<", [61] = "=", [62] = ">", [63] = "?", [64] = "@", [65] = "A", [66] = "B", [67] = "C", [68] = "D", [69] = "E", [70] = "F", [71] = "G", [72] = "H", [73] = "I", [74] = "J", [75] = "K", [76] = "L", [77] = "M", [78] = "N", [79] = "O", [80] = "P", [81] = "Q", [82] = "R", [83] = "S", [84] = "T", [85] = "U", [86] = "V", [87] = "W", [88] = "X", [89] = "Y", [90] = "Z", [91] = "[", [92] = "\\", [93] = "]", [94] = "^", [95] = "_", [96] = "`", [97] = "a", [98] = "b", [99] = "c", [100] = "d", [101] = "e", [102] = "f", [103] = "g", [104] = "h", [105] = "i", [106] = "j", [107] = "k", [108] = "l", [109] = "m", [110] = "n", [111] = "o", [112] = "p", [113] = "q", [114] = "r", [115] = "s", [116] = "t", [117] = "u", [118] = "v", [119] = "w", [120] = "x", [121] = "y", [122] = "z", [123] = "{", [124] = "|", [125] = "}", [126] = "~", [127] = "^?", [128] = "M-^@", [129] = "M-^A", [130] = "M-^B", [131] = "M-^C", [132] = "M-^D", [133] = "M-^E", [134] = "M-^F", [135] = "M-^G", [136] = "M-^H", [137] = "M-^I", [138] = "M-^J", [139] = "M-^K", [140] = "M-^L", [141] = "M-^M", [142] = "M-^N", [143] = "M-^O", [144] = "M-^P", [145] = "M-^Q", [146] = "M-^R", [147] = "M-^S", [148] = "M-^T", [149] = "M-^U", [150] = "M-^V", [151] = "M-^W", [152] = "M-^X", [153] = "M-^Y", [154] = "M-^Z", [155] = "M-^[", [156] = "M-^\\", [157] = "M-^]", [158] = "M-^^", [159] = "M-^_"};

int initFlags(Flags *flags);

int getFlags(char *argv, Flags *flags);

int handle_flag_b(char previous_line, int *count_empty_line, char ch);

int handle_flag_n(int start_line, int *count_all_line, char ch);

int handle_flag_s(char previous_char, char next_char, char ch);

int handle_flag_v(char *ch);

int handle_flag_E(char ch);

int handle_flag_T(char ch);

void cat(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    if (argc > 1)
        cat(argc, argv);
    else
        printf("cat: flags empty and file...");
    return 0;
}

int initFlags(Flags *flags)
{
    flags->b = 0;
    flags->e = 0;
    flags->E = 0;
    flags->v = 0;
    flags->n = 0;
    flags->s = 0;
    flags->t = 0;
    flags->T = 0;
    return 1;
}

void cat(int argc, char *argv[])
{
    Flags flags;
    initFlags(&flags);

    int error = 0;
    int i = 1;
    for (; i < argc; ++i)
    {
        if (strspn(argv[i], "-") == 0)
            break;
        if (getFlags(argv[i], &flags) == 1)
            error = 1;
    }
    if (flags.b)
        flags.n = 0;
    if (!error && i == argc)
    {
        printf("cat: please input filename...");
    }
    for (; !error && i < argc; ++i)
    {
        FILE *file_name = fopen(argv[i], "r");
        if (file_name)
        {
            int start_line = 1;
            // count line for flags->b -- numbers only no-empty lines
            int count_empty_line = 1;
            // count line for flags->n -- number all output lines
            int count_all_line = 1;
            char previous_char = '\n';
            char next_char = ' ';
            char ch[1024] = {'\0'};

            while ((*ch = fgetc(file_name)) != EOF)
            {
                if (flags.s && handle_flag_s(previous_char, next_char, *ch))
                    continue;
                if (flags.n)
                    start_line = handle_flag_n(start_line, &count_all_line, *ch);
                if (flags.b)
                    handle_flag_b(previous_char, &count_empty_line, *ch);
                if (flags.E)
                    handle_flag_E(*ch);
                if (flags.v)
                    handle_flag_v(ch);
                next_char = previous_char;
                previous_char = *ch;
                if (flags.T && handle_flag_T(*ch))
                    continue;
                if (*ch == '\0')
                    fputc(*ch, stdout);
                else
                    fputs(ch, stdout);
                memset(ch, '\0', 1024);
            }
        }
        else
        {
            printf("cat: Can't open '%s': No such file or directory!\n", argv[i]);
        }
        fclose(file_name);
    }
    if (error)
        printf("cat: illegal option -- '%s'.\nTry 'man cat' for more information.",
               argv[i - 1]);
}

int handle_flag_b(char previous_char, int *count_empty_line, char ch)
{
    if (previous_char == '\n' && ch != '\n')
        printf("%6d\t", (*count_empty_line)++);
    return ch == '\n';
}

int handle_flag_v(char *ch)
{
    unsigned char tmp = *ch; // 124
    if ((tmp <= 8) || (tmp >= 11 && tmp <= 31) || (tmp >= 127 && tmp <= 159))
        strcpy(ch, special_symbol[tmp]);
    return tmp;
}

int handle_flag_E(char ch)
{
    if (ch == '\n')
        printf("$");
    return ch == '\n';
}

int handle_flag_n(int start_line, int *count_all_line, char ch)
{
    if (start_line)
        printf("%6d\t", (*count_all_line)++);
    return ch == '\n';
}

int handle_flag_s(char previous_char, char next_char, char ch)
{
    return ch == '\n' && previous_char == '\n' && next_char == '\n';
}

int handle_flag_T(char ch)
{
    int tab = 0;
    if (ch == '\t')
        tab = printf("^I");
    return tab;
}

// int getFlags(char *argv, Flags *flags)
// {
//     int error = 0;
//     if (strlen(argv) == 1 || strlen(argv) != strspn(argv, "-bvEnsTet"))
//         error = 1;
//     if (!strcmp(argv, "--number"))
//     {
//         error = 0;
//         flags->n = 1;
//     }
//     else if (!strcmp(argv, "--number-nonblank"))
//     {
//         error = 0;
//         flags->b = 1;
//     }
//     else if (!strcmp(argv, "--squeeze-blank"))
//     {
//         error = 0;
//         flags->s = 1;
//     }
//     else
//     {
//         if (strchr(argv, 'b'))
//             flags->b = 1;
//         if (strchr(argv, 'e'))
//         {
//             flags->v = 1;
//             flags->E = 1;
//         }
//         if (strchr(argv, 'E'))
//             flags->E = 1;
//         if (strchr(argv, 'v'))
//             flags->v = 1;
//         if (strchr(argv, 'n'))
//             flags->n = 1;
//         if (strchr(argv, 's'))
//             flags->s = 1;
//         if (strchr(argv, 't'))
//         {
//             flags->v = 1;
//             flags->T = 1;
//         }
//         if (strchr(argv, 'T'))
//             flags->T = 1;
//     }
//     return error;
// }