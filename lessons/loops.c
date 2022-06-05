#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int main() {

	// Цикл #1:
	// 		1. Объявляется переменная;
	// 		2. Создается условие
	// 		3. Условие, как изменяется переменная
	for(float i = 100; i > 10; i /= 2) {
		printf("%.2f\n", i);
	}

	bool isCar = true;
	int y = 0;
	// Цикл #2:
	// 		1. Создается условие
	while(isCar) {
		printf("Введите цифру: \n");
		scanf("%d", &y);
		if (y == 1)
			isCar = false;
	}

	// Цикл #3:
	int i = 0;
	while (i < 10) {
		printf("%d\n", i);
		i++;
	}

	// Цикл #4:
	// Принцип основан на сперва один раз точно выполняет функцию,
	// 			затем проверяет условие, а после выполненяет функцию,
	// 			и дальше все по кругу.
	bool isHasCar = false;
	do {
		printf("Yes\n");
	} while(isHasCar);



	for(int y = 0; y < 10; y++) {
		if (y == 3)
			break;

		if (y % 2 == 0){
			continue;
		}
		printf("%d\n", y);
	}

	int u = 0;
	int arr[] = {5, 67, 0, -2, 6};

	printf("Loop FOR:\n");
	for(u; u < 5; u++)
		printf("%d, ", arr[u]);


	u = 0;
	printf("\nLoop WHILE: \n");
	while(u < 5) {
		printf("%d, ", arr[u]);
		u++;
	}

	printf("\nLoop DO WHILE: \n");
	u = 0;
	do {
		printf("%d, ", arr[u]);
		u++;
	} while (u < 5);

	int min = arr[0];
	int max = arr[0];

	printf("\n");
	for (int i = 0; i < 5; i++) {
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	printf("Minimum: %d\n", min);
	printf("Maximum: %d\n", max);

	return 0;
}
