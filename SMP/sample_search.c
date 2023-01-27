#include <stdio.h>
#include <conio.h>

#define MAXLINE 1000 // Максимальная длина входной строки

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // Образец для поиска

int main() {
	char line[MAXLINE];
	int found = 0;

	while (getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s\n", line);
			found++;
		}
	return found;
}

int getline(char s[], int lim){
	int c, i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strindex(char s[], char t[]) {
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}


