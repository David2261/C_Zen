GG = gcc -Wall -Wextra -Werror
SOURCE = dip.c

all: DIP

DIP: $(SOURCE)
	$(GG) $(SOURCE)
	$(MAKE) DIP.o

DIP.o: $(SOURCE)
	./a.out

clean: ./a.out
	rm -f a.out
