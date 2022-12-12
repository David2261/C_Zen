LIB="grep"
TEST="regex -e ^print s21_grep.c -v -n -l -f test_ptrn_grep.txt"

# Основная часть (выполнение функции s21 и системной функции)
./s21_$LIB $TEST > test_s21.txt
$LIB $TEST > test_$LIB.txt

# Быстрая проверка
diff -s test_s21.txt test_$LIB.txt

# Сравнение текста в визуальном просмотрщике
# opendiff test_s21.txt test_$LIB.txt

# Сравнение в 16-ричном виде в визуальном просмотрщике
#hexdump test_s21.txt > test_s21_hex.txt
#hexdump test_$LIB.txt > test_$LIB_hex.txt
#opendiff test_s21_hex.txt test_$LIB_hex.txt
