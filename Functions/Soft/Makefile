.PHONY: all clear print_module create_test insert_test traverse_test

GG = gcc
GF = -Wall -Werror -Wextra
GO = -o

SOURCE_1 = print_module.c main_module_entry_point.c
OBJECTS_1 = print_module.o main_module_entry_point.o

SOURCE_2 = bst.c bst_greate_test.c
OBJECTS_2 = bst.o bst_greate_test.o

SOURCE_3 = bst.c bst_insert_test.c
OBJECTS_3 = bst.o bst_greate_test.o

SOURCE_4 = bst.c bst_traverse_test.c
OBJECTS_4 = bst.o bst_traverse_test.o

T1 = ./build/data_1
T2 = ./build/data_2
T3 = ./build/data_3
T4 = ./build/data_4

all: print_module create_test insert_test traverse_test

# 1
print_module: $(SOURCE_1)
	$(GG) $(GF) $(SOURCE_1)
	$(MAKE) a1.o

a1.o: $(OBJECTS_1)
	$(GG) $(GO) $(T1) $(OBJECTS_1)
	$(MAKE) run_1

run_1: $(T1)
	$(T1)

# 2
create_test: $(SOURCE_2)
	$(GG) $(GF) $(SOURCE_2)
	$(MAKE) a2.o

a2.o: $(OBJECTS_2)
	$(GG) $(GO) $(T2) $(OBJECTS_2)
	$(MAKE) run_2

run_2: $(T2)
	$(T2)

# 3
insert_test: $(SOURCE_3)
	$(GG) $(GF) $(SOURCE_3)
	$(MAKE) a3.o

a3.o: $(OBJECTS_3)
	$(GG) $(GO) $(T3) $(OBJECTS_3)
	$(MAKE) run_3

run_3: $(T3)
	$(T3)

# 4
traverse_test: $(SOURCE_4)
	$(GG) $(GF) $(SOURCE_4)
	$(MAKE) a4.o

a4.o: $(OBJECTS_4)
	$(GG) $(GO) $(T4) $(OBJECTS_4)
	$(MAKE) run_4

run_4: $(T4)
	$(T4)

clear: $(SOURCE_1)
	rm -rf *.out
	rm ./build/*