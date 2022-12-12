#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
RESULT=0
DIFF_RES=""

declare -a tests=(
"s test/test_0_grep.txt VAR"
"for grep.c grep.h Makefile VAR"
"for grep.c VAR"
"-e for -e ^int grep.c grep.h Makefile VAR"
"-e for -e ^int grep.c VAR"
"-e regex -e ^print grep.c VAR -f test/test_ptrn_grep.txt"
"-e while -e void grep.c Makefile VAR -f test/test_ptrn_grep.txt"
)

declare -a extra=(
"-n for test/test_1_grep.txt test/test_2_grep.txt"
"-n for test/test_1_grep.txt"
"-n -e ^\} test/test_1_grep.txt"
"-c -e /\ test/test_1_grep.txt"
"-ce ^int test/test_1_grep.txt test/test_2_grep.txt"
"-e ^int test/test_1_grep.txt"
"-nivh = test/test_1_grep.txt test/test_2_grep.txt"
"-e"
"-ie INT test/test_5_grep.txt"
"-echar test/test_1_grep.txt test/test_2_grep.txt"
"-ne = -e out test/test_5_grep.txt"
"-iv int test/test_5_grep.txt"
"-in int test/test_5_grep.txt"
"-c -l aboba test/test_1_grep.txt test/test_5_grep.txt"
"-v test/test_1_grep.txt -e ank"
"-noe ) test/test_5_grep.txt"
"-l for test/test_1_grep.txt test/test_2_grep.txt"
"-o -e int test/test_4_grep.txt"
"-e = -e out test/test_5_grep.txt"
"-noe ing -e as -e the -e not -e is test/test_6_grep.txt"
"-e ing -e as -e the -e not -e is test/test_6_grep.txt"
"-c -e . test/test_1_grep.txt -e '.'"
"-l for test/no_file.txt test/test_2_grep.txt"
"-f test/test_3_grep.txt test/test_5_grep.txt"
)

testing()
{
    t=$(echo $@ | sed "s/VAR/$var/")
    leaks -quiet -atExit -- ./grep $t > test_s21_grep.log
    leak=$(grep -A100000 leaks test_s21_grep.log)
    (( COUNTER++ ))
    if [[ $leak == *"0 leaks for 0 total leaked bytes"* ]]
    then
      (( SUCCESS++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m grep $t"
    else
      (( FAIL++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m grep $t"
#        echo "$leak"
    fi
    rm test_s21_grep.log
}

# специфические тесты
for i in "${extra[@]}"
do
    var="-"
    testing $i
done

# 1 параметр
for var1 in v c l n h o
do
    for i in "${tests[@]}"
    do
        var="-$var1"
        testing $i
    done
done

# 2 параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1 -$var2"
                testing $i
            done
        fi
    done
done

# 3 параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        for var3 in v c l n h o
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1 -$var2 -$var3"
                    testing $i
                done
            fi
        done
    done
done

# 2 сдвоенных параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                var="-$var1$var2"
                testing $i
            done
        fi
    done
done

# 3 строенных параметра
for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        for var3 in v c l n h o
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    var="-$var1$var2$var3"
                    testing $i
                done
            fi
        done
    done
done

echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"
