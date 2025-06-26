#include <stdio.h>
#include <math.h>

int main() {
    double a;
    // Считывание числа с плавающей точкой
    printf("Введите число a: ");
    scanf("%lf", &a);
    double result;
    // Если a больше 0, модуль (a - 1)
    if (a > 0)
        result = fabs(a - 1);
    // Иначе модуль (a + 1)
    else
        result = fabs(a + 1);
    // Результат
    printf("%lf\n", result);
    return 0;
}
