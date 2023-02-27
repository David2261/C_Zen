GG = gcc -Wall -Wextra -Werror
SOURCE = isp.c

all: ISP

ISP: $(SOURCE)
	$(GG) $(SOURCE)
	$(MAKE) ISP.o

ISP.o: $(SOURCE)
	./a.out

clean: ./a.out
	rm -f a.out
