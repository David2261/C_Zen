#include <stdio.h>
#include <conio.h>


int main(){
	// Указатель
	// Фукнции с открытым файлом:
	// 		[r - read, w - write, a - append (only append new datas)]
	// FILE *переменная = открытие файла("Адрес в директории", "работа с ним")
	//
	char line[255];
	FILE *file = fopen("test.txt", "r");


	// Запись внутри самого файла
	fprintf(file, "Hello dude!\n");

	fgets(line, 255, file);
	printf("%s\n", line);


	fclose(file);




	return 0;
}
