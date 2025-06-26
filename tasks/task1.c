#include <stdio.h>
#include <math.h>

int main() {
    // Объявление переменных
    double x, y, z;     // Входные значения
    double a, b;        // Результаты

    // Ввод значений x, y, z
    printf("Введите значения x, y, z: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    // a
    // числитель
    double numerator_a = x + y / (x * x + 4);

    // знаменатель
    double denominator_a = exp(-x - 2) + 1 / (x * x + 4);

    // ответ a
    a = (1 + y) * (numerator_a / denominator_a);

    // b
    // числитель
    double numerator_b = (1 + cos(y - 2)) / (x * x * x * x);

    // знаменатель
    double denominator_b = (x * x * x * x) / 2 + pow(sin(z), 2);

    // ответ b
    b = numerator_b / denominator_b;

    // Вывод результатов
    printf("Результаты:\n");
    printf("a = %.6f\n", a);
    printf("b = %.6f\n", b);

    return 0;
}