#include <stdio.h>
#include <conio.h>


// Объявление структуры данных
struct Car{
	int speed;
	// [кол-во символов]
	char name[50];
	float weight;
};

int main(){
	
	struct Car Audi;
	Audi.speed = 250;
	// Для установки строк внутри массива
	strcpy(Audi.name, "Audi A8");
	Audi.weight = 2500.00f;


	struct Car Mercedes = {300, "Mercedes GLS", 2700.00f};

	printf("%s his speed: %d\n", Audi.name , Audi.speed);
	printf("%s his speed: %d\n", Mercedes.name , Mercedes.speed);


	return 0;
}