#include <stdio.h>
#include <conio.h>


int main(){

	long nc = 0;

	while(getchar() != EOF) {
		++nc;
		printf("%1d\n", nc);
	}
	return 0;
}
