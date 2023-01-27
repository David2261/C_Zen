LIB="grep"
TEST="regex -e ^print grep.c -v -n -l -f test/test_ptrn_grep.txt"

# Основная часть
./$LIB $TEST > test_s21.txt
$LIB $TEST > test_$LIB.txt

# Быстрая проверка
diff -s test/test_s21.txt test/test_$LIB.txt

# Сравнение текста в визуальном просмотрщике
# opendiff test_s21.txt test_$LIB.txt

# Сравнение в 16-ричном виде в визуальном просмотрщике
#hexdump test_s21.txt > test_s21_hex.txt
#hexdump test_$LIB.txt > test_$LIB_hex.txt
#opendiff test_s21_hex.txt test_$LIB_hex.txt
