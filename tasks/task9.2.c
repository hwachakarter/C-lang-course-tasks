#include <stdio.h> // для ввода-вывода
// для assert
#include <assert.h>

// модуль для матрицы
#include "../modules/matrix.h"



// Процедура для решения задачи
void solve() {
    int n;
    int min, max;

    printf("Программа ищет максимальное число в матрице по шаблону\n");
    printf("1 1 1\n");
    printf("0 1 0\n");
    printf("0 0 0\n\n");
    printf("Введите размер матрицы n: ");
    scanf("%d", &n);
    printf("Введите минимум и максимум для генерации случайных чисел: ");
    scanf("%d %d", &min, &max);

    int** matrix = generate_random_matrix(n, min, max);

    // Вывод сгенерированной матрицы
    print_matrix(n, matrix);

    // Поиск максимального числа по заданному шаблону
    int max_value = max_num_by_pattern(n, matrix);
    printf("Максимальное число по шаблону: %d\n", max_value);
}

int main() {  
    assert(max_num_by_pattern(3, 
        (int*[]) { 
            (int[]){1, 2, 3}, 
            (int[]){4, 5, 6}, 
            (int[]){7, 8, 9} 
        }) == 5); // Проверка для 3x3 матрицы

    solve();
    return 0;
}