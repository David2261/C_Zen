#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_
#include <regex.h>

#include "../common/main.h"

int init_str(Option_2 *opt);
int read_set(int, char **, char **, char **, Option_2 *);
int taker(char *, Option_2 *opt);
int regular_expression(char *, char **, int *);

int grep(Option_2 *opt, char *, char **, int);
int comparison(const char *const, char **, char **, const Option_2 *opt);

#endif  // SRC_GREP_S21_GREP_H_