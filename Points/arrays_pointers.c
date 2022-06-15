#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // Максимальное количество сортируемых строк

#char *lineptr[MAXLINES]; // Указатели на строки

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

// Сортировка строк входного потока
main() {
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("Error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN 1000 // Сортировка строк входного потока
int getline(char *, int);
char *alloc(int);

// Количество введенных строк
int readlines(char *lineptr[], int maxlines) {
	int len, nlines = 0;
	char *p, line[MAXLEN];

	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0'; // Удаление конца строки
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}


// Вывод строк в выходной поток
void writelines(char *lineptr[], int nlines) {
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

