#include <stdio.h>
#include <conio.h>
// Библиотека для использования булевых выражений
#include <stdbool.h>

int main() {
	int x = 9;

	bool isCar = true;

	// Можно проверить на: 
	// 		[==, <, >, >=, <=, !=]
	// 	Можно использовать условия:
	// 		[&& - и, || - или, ]
	if(x == 7 || x < 10) {
		printf("Yes\n");
	} else if(x > 100) {
		if (x < 150)
			printf("Normal number\n");
		printf("Very higher than need!!!\n");
	} else {
		printf("No\n");
	}

	// Можно писать, как isCar == true или
	// 		isCar
	// Можно написать, как isCar == false или
	// 		!isCar
	if (isCar){
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	int d = 30;

	switch (d) {
		// Проверка на точное совпадение\
		// Принцип основан на том, что проверяется каждый кейс,
		// 		а break останавливает эту проверку
		case 10:
			printf("Equil 10\n");
			break;
		case 15:
			printf("Equil 15\n");
			break;
		case 20:
			printf("Equil 20\n");
			break;
		case 25:
			printf("Equil 25\n");
			break;

		// Если же ни один кейс не сработал, то ничего не выводиться
		
		default:
			// или можно просто выводить значение по дефолту.
			// Похожа на else в условной функции
			printf("Equil %5d\n", d);
			break;
	}



	return 0;
}