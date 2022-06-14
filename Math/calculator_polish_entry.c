#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 // Максимальный размер операнда или знака
#define NUMBER '0' // Сигнал, что обнаружено число

#int getop();
void push(double);

// Калькулятор с обратной польской записью
int main() {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("Error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.9g\n", pop());
				break;
			default:
				printf("Error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}
