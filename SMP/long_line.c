#include <stdio.h>
#include <conio.h>

#define MAXLINE 1000 // Максимальная длина строки в потоке

int getline(char line[], int maxline);
void copy(char to[], char from []);

// Вывод самой длинной строки в потоке

int main(){
	// len - длина текущей строки
	// max - текущая максимальная строка
	int len, max = 0;

	char line[MAXLINE]; // текущая введеная строка
	char longest[MAXLINE]; // самая длинная строка из введенных

	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}

	if (max > 0)
		printf("%s\n", longest);
	return 0;
}

// Считывает строку в s, возвращает её длину
int getline(char s[], int lim) {
	int c, i;
	for (i = 0; i< lim-1 && (c-getchar()) != EOF && c! = '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}

	return i;
}

// Копирует строку 'from' в 'to'; длина to считается достаточной
void copy(char to[], char from[]){
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}