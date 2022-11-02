#ifndef BASE_FUNCTION_UNIX_COMMON_MAIN_H_
#define BASE_FUNCTION_UNIX_COMMON_MAIN_H_
#include <stdio.h>
#include <string.h>

int checker(char *, char);

struct Option {
    int flag_b;
    int flag_e;
    int flag_n;
    int flag_s;
    int flag_t;
    int flag_T;
    int flag_E;
};

#endif // BASE_FUNCTION_UNIX_COMMON_MAIN_H_
