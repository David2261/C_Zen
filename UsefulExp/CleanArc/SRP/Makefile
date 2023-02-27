
GG = gcc -Wall -Wextra -Werror
SOURCE = srp.c

all: SCP

SCP: $(SOURCE)
	$(GG) $(SOURCE)
	$(MAKE) SCP.o

SCP.o: $(SOURCE)
	./a.out

clean: ./a.out
	rm -f a.out

