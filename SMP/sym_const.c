#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

// Константы - пишутся только (Согласна стандартам) с большой буквы.
// 		*Можно писать с маленькой, но это портит вид программы
#define LOWER 0 // Нижний уровень предела
#define STEP 20 // Размер шага
#define UPPER 300 // Верхний уровень предела

int main(){
	int fahr;

	for(fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}

	return 0;
}

