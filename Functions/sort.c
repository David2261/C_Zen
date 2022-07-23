#include <stdio.h>
#define NMAX 10

int input(int *a);
void sort(int *data);

int main() {
	int data[10];
	input(data);
	sort(data);
	return 0;
}


int input(int *a) {
	printf("Write your number: ");
	scanf("%d", a);
	return 0;
}

// Сортировка пузырьком
void sort(int *data) {
	int j;
	for (int i = 0; i < data; i++) {

		if (data[j] < data[j-1]) {
			int t = data[j-1];
			data[j-1] = data[j];
			data[j] = t;
		}
	}
}

