

GG = gcc
GF = -Wall -Werror -Wextra
GO = -o

# 1
SOURCE_ARRAY = arrays_pointers.c
OBJECT_ARRAY = arrays_pointers.o
DATA_ARRAY = ./build/array

# 2
SOURCE_SORT = bubble_sort.c
OBJECT_SORT = bubble_sort.o
DATA_SORT = ./build/sort

# 1
array: $(SOURCE_ARRAY)
	$(GG) $(GF) $(SOURCE_ARRAY)
	$(MAKE) arr.o

arr.o: $(OBJECT_ARRAY)
	$(GG) $(GO) $(DATA_ARRAY) $(OBJECT_ARRAY)
	$(MAKE) arr.run

arr.run: $(DATA_ARRAY)
	$(DATA_ARRAY)

# 2
sort: $(SOURCE_SORT)
	$(GG) $(GF) $(SOURCE_SORT)
	$(MAKE) sort.o

sort.o: $(OBJECT_SORT)
	$(GG) $(GO) $(DATA_SORT) $(OBJECT_SORT)
	$(MAKE) sort.run

sort.run: $(DATA_SORT)
	$(DATA_SORT)
