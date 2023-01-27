#include <stdio.h>
#include <conio.h>

// getchar - это функция считывает следующий символ текстового потока
// 			ввода и возращает его в качестве своего значения
// putchar - это функция, которая при каждом вызове выводит 1 символ
int main(){
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
}

// EOF - (end of file) - конец файла, это целое число