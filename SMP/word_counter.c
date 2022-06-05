#include <stdio.h>
#include <conio.h>

#define IN 1 // Внутри слова
#define OUT 0 // Вне слова


int main(){

	int c, nl = 0, nw = 0, nc = 0, stats = OUT;

	while(()) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);

	return 0;
}