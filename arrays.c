#include <stdio.h>
#include <conio.h>


int main() {
	// Обязательно нужно объявлять количество элементов внутри массива
	// или можно сразу добавить все элементы в массив и не писать 
	// 								количество элементов в массиве
	int arr[5] = {5, 7, 5, 68, 34};

	arr[0] = 73;

	printf("%d\n", arr[0]);


	float numbers[3];

	numbers[0] = 5.4f;
	numbers[1] = 4.23f;
	numbers[2] = 67.34f;

	char word[] = {'S', 'o', 'm', 'e'};

	char words[] = "Hello Word!";

	words[1] = 'G';

	// Для вывода всех символов массива
	printf("%s\n", words);

	// Для вывода символа с индексом [1] - массива
	printf("%c\n", words[1]);

	//
	int array[3][4] = {
		{4, 7, 9, 1},
		{1, 234, 8, 6},
		{46, 0, 34, 5},
	};

	array[1][1] = 898;

	printf("%d\n", array[1][1]);



	return 0;
}