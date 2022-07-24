.PHONY: all clean rebuild print_module bst_create_test bst_insert_test bst_traverse_test

all: print_module bst_create_test bst_insert_test bst_traverse_test

rebuild: clean all

clean:
	cd ..
	rm -f -r *.o

print_module:../build/Quest_1

bst_create_test:../build/Quest_3

bst_insert_test:../build/Quest_4

bst_traverse_test:../build/Quest_5


../build/Quest_1:print_module.c main_module_entry_point.c
	gcc -Wall -Werror -Wextra $^ -o $@

../build/Quest_3:bst.c bst_greate_test.c
	gcc -Wall -Werror -Wextra $^ -o $@

../build/Quest_4:bst.c bst_insert_test.c
	gcc -Wall -Werror -Wextra $^ -o $@

../build/Quest_5:bst.c bst_traverse_test.c
	gcc -Wall -Werror -Wextra $^ -o $@

.c.o:
	gcc -Wall -Werror -Wextra -c $< 
