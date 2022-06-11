#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAXLINE 100
double sum, atof(char s[]);

int main() {
	double sum = 0, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

// Преобразование строки s в число типа double
double atof(char s[]) {
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)
		; // Пропуск пробелов
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == '.')
		i++;
    for (val = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;

}
