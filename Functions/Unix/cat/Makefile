GG = gcc
GF = -Wall -Wextra -Werror -std=c11 -D_GNU_SOURCE

all: s21_cat

s21_cat:
	$(GG) $(GF) s21_cat.c ..comon/check.c -o s21_cat



clean:
	rm -f ./s21_cat

rebuild: clean all