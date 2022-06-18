#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdarg.h>

// Переводит выходные данные в нижний регистр
int main(){
	int c;

	while ((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
	printf("%\n");
}

// Упрощенная версия printf, со списком арг. переменной длины
void minprintf(char *fmt, ...) {
	va_list ap; // Указывает на безымянный аргумент
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); // Устанавливает ap на 1-ый аргумент без имени
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}

