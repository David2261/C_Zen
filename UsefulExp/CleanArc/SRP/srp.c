#include "srp.h"


int main() {
    /* Это типо Глобальный класс Employee */
    int *data = (int*)malloc(sizeof(int) * 1);
    int days = 21;
    int overtimeHs = 16;
    int pay = calculatePay(days, overtimeHs); // Для бухгалтерии
    int report = reportHours(days, overtimeHs); // Для HR
    save(data, pay, report);
 
    for (int i = 0; i < 2; i++) printf("%d\n", data[i]);
    return 0;
}

int calculatePay(int days, int overtime) {
    int hours = regularHours(days);
    int rate = 699;
    hours = hours + overtime;
    return rate * hours;
}

int reportHours(int days, int overtime) {
    int hours = regularHours(days);
    return hours + overtime;
}

int regularHours(int days) {
    int hours = 8;
    return hours * days;
}

void save(int *x, int pay, int report) {
    x = (int *)realloc(x, 2);
    x[0] = pay;
    x[1] = report;
}

