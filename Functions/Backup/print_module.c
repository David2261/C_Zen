#include <stdio.h>
#include <time.h>

#include "print_module.h"

int print_char(char ch) {
    return putchar(ch);
}

void print_log(int (*print)(char), char* message) {
    time_t t = time(NULL);
    struct tm* aTm = localtime(&t);
    char  buffer[200];
    int j = 0;

    j  = sprintf(buffer, Log_prefix);
    j += sprintf(buffer + j, " %02d:%02d:%02d ", aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    j += sprintf(buffer + j, "%s", message);
    j = 0;
    while (buffer[j] != '\0') {
        (*print)(buffer[j]);
        j++; }
}
