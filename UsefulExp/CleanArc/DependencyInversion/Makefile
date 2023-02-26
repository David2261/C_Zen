
GG = gcc -Wall -Werror -Wextra

SOURCE = obfuscate.c

all: Obfuscate

Obfuscate: $(SOURCE)
	$(GG) $(SOURCE)
	$(MAKE) Obs

Obs: $(SOURCE)
	./a.out

clean: ./a.out
	rm -f ./a.out

