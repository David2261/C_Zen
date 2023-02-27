
GG = gcc -Wall -Wextra -Werror
SOURCE = lsp.c

all: LSP

LSP: $(SOURCE)
	$(GG) $(SOURCE)
	$(MAKE) LSP.o

LSP.o: $(SOURCE)
	./a.out

clean: ./a.out
	rm -f a.out


