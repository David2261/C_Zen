#include <stdio.h>
#include <conio.h>

// Сцепление файлов по порядку
int main(int argc, char *argv[]){
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1) // Стандартный поток
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("Cat: can't open %s\n", *argv);
				return 1;
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;
}

// Копирование файла ifp в файл ofp
void filecopy(FILE *ifp, FILE *ofp) {
	int c;

	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

// Считывает не более n символов из iop
char *fgets(char *s, int n, FILE *iop) {
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

// Вывод строки s в файл iop
int fputs(char *s, FILE *iop) {
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}

// Считывает строку и возвращает её длину
int getline(char *line, int max) {
	if (fgets(line, max, stdin) == NULL)
		return NULL;
	else
		return strlen(line);
}


