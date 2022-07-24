#include <stdio.h>
#include <conio.h>


int main(){
	int day = 0, year = 0;
	char monthname[20];

	scanf("%d %s %d", &day, month, &year);

	while (getline(line, sizeof(line)) > 0) {
		if (sscanf(line, "%d %s %d", &day, month, &year) == 3)
			printf("Valid: %s\n", line); // 25  дек 1988
		if else (sscanf(line, "%d %d %d", &day, month, &year))
			printf("Valid: %s\n", line) // мм/дд/гг
		else
			printf("Invalid: %s\n", line); // Ошибка
	}
}