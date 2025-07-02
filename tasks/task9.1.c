#include <stdio.h> // для ввода-вывода
#include <assert.h> // для assert
#include "../modules/fib.h" 

// Процедура ввода и вывода числа Фибоначчи
void solve() {
    int n, result;

    printf("Введите неотрицательное целое число n для вычисления числа Фибоначчи по индексу n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Введено отрицательное число.\n");
    }

    result = fib(n);
    printf("Fib(%d) = %d\n", n, result);
}

int main() {
    assert(fib(6) == 8); // Проверка для n = 6
    assert(fib(10) == 55); // Проверка для n = 10

    solve();
    return 0;
}