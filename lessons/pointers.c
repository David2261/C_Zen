#include <stdio.h>
#include <conio.h>


struct Abstract{
	int weight, height;

};

// Без указателей
void calc(struct Abstract obj);
// С указателем
void calc_p(struct Abstract *obj);

// Указатель - это переменная, которая содержит АДРЕС другого объекта

int main() {

	int x = 0;

	// Содержит не значение, а адресс переменной
	int *pX = &x;

	// Hash - adress
	printf("%p\n", pX);
	// Выводит значение, через память пк
	printf("%d\n", *pX);

	// Изменяет значение переменной, через указатель
	*pX = 10;
	printf("*pX: %d - x: %d\n", *pX, x);


	struct Abstract square = {5, 7};
	calc(square);


	calc_p(&square);

	return 0;
}


void calc(struct Abstract obj) {
	int res = obj.weight * obj.height;
	printf("Result: %d\n", res);
}


void calc_p(struct Abstract *obj) {
	int res = obj->weight * obj->height;
	printf("Result: %d\n", res);
}
