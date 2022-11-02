#ifndef BASE_FUNCTION_UNIX_COMMON_S_CAT_H_
#define BASE_FUNCTION_UNIX_COMMON_S_CAT_H_
#include "../common/main.h"


int read_file(char **, struct Option *opt);
int cat(struct Option opt, FILE* file, int count);

#endif // BASE_FUNCTION_UNIX_COMMON_S_CAT_H_