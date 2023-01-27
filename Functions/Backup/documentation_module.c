#include "documentation_module.h"
#include stdarg.h

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}
/*
int* check_available_documentation_module(int (*validate) (char*), int document_count, ...) {
    va_list argptr;
    va_start(argptr, str);

    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for(int i=0;i<n; i++)
        {
            result += va_arg(factor, char *);  // получаем значение текущего параметра типа int
        }
        va_end(factor); // завершаем обработку параметров
}
*/
