#include <stdio.h>
#include <conio.h>


int main() {
	int i;

	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));

	return 0;
}

// Функция возведения в степень
int power(int base, int n) {
	int i, p = 1;

	for (i = 1; i <= n; ++i)
		p = p * base;

	return p;
}