#include <stdio.h> // для ввода-вывода

int main() {
    int n, reversed = 0;
    // Считывание числа
    printf("Введите натуральное число n для разворота: ");
    scanf("%d", &n);

    // цикл для разворота числа
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (n <= 0) {
        printf("Число должно быть натуральным.\n");
        return 1;
    }

    printf("Обратный порядок: %d\n", reversed);
    return 0;
}