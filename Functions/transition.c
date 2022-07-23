/*
Ввод обычного текста с нижним индексом,
после перевод первого символа в верхний уровень.
Example:
add some text!
Add Some Text!
*/
#include <stdio.h>
#define MAX 100

int main() {
	char str[MAX];
	int i = 0;
	if (scanf("%[^\n]s", str) == 1)
		for (i = 0; str[i] != '\0'; i++) {
			if (i == 0) {
				if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
				continue;
			}
			if (str[i - 1] < 65 || (str[i - 1] > 90 && str[i - 1] < 97) || str[i - 1] > 122) {
				if (str[i] >= 'a' && str[i] <= 'z') {
					str[i] -= 32;
					continue;
				}
			} else {
				if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
			}
		}
	printf("%s\n", str);
	return 0;
}
