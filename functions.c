#include <stdbool.h>
// Подключаем функцию
#include "functions_refill.h"


// Объявляем все используемые функции
void base(int a, int b);
float mult(float a, float b);

// Данная функция возвращает определенное значение, например 0
int main(){
	base(20, 50);
	int x = 5, y = 7;
	base(x, y);
	char word[] = {'s', 'o', 'm', 'e'};
	string(word);

	// Можно объявить переменную,
	// которая принимает значение res.
	// Т.к. мы прописали, что функция mult
	// выпускает это значение 
	float result = mult(4.5f, 7.8f);
	printf("%.2f\n", result);
	// 35.1

	return 0;
}


// Данная функция ничего не возрашает, т.е.
// её тип void
// Она не принимает никакие параметры
void base(int a, int b){
	int res = a + b;
	printf("Result: %d\n", res);
}



float mult(float a, float b){
	float res = a * b;
	printf("Conclusion: %.2f\n", res);
	// Conclusion: 35.1
	return res;
}