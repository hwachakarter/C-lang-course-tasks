#include <stdio.h> // для ввода-вывода
#include <math.h> // для математических функций
// для рандомных чисел
#include <stdlib.h>
#include <time.h>
// для assert
#include <assert.h>

#define N 1024 // максимальный размер матрицы

// Функция для заполнения матрицы matrix рандомными числами n x n
float generate_matrix(int n, float matrix[N][N]) {
    // инициализация генератора случайных чисел
    srand(time(NULL));

    // заполнение матрицы рандомными числами
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (float)(rand() % 201 - 100) / 100.0f; // числа от -1.00 до 1.00
        }
    }
    
    return matrix[n][n];
}

// Функция для поиска максимального числа в определённом диапазоне
// диапозон:
// 1 1 1
// 0 1 0
// 0 0 0
float max_num_by_pattern(int n, float matrix[N][N]) {
    float max_num = 0; // максимальное число
    int row = 0; // текущая строка, первая - 0

    for (int i = 0; i < n; i++) {
        // проверка осуществляется убирая одно число
        // с начала и конца каждой новой строки
        for (int j = row; j < n-row; j++) {
            // проверка на максимальное число
            if (matrix[i][j] > max_num) {
                max_num = matrix[i][j];
            }
        }
        row++; // переход к следующей строке
    }

    return max_num;

}

// Процедура для решения задачи
void solve() {
    int n;

    printf("Программа ищет максимальное число в матрице по шаблону\n");
    printf("1 1 1\n");
    printf("0 1 0\n");
    printf("0 0 0\n\n");
    printf("Введите размер матрицы n (1 <= n <= %d): ", N);
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Размер матрицы должен быть в диапазоне от 1 до %d.\n", N);
        return;
    }

    float matrix[N][N];
    generate_matrix(n, matrix);

    // Вывод сгенерированной матрицы
    printf("Сгенерированная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    // Поиск максимального числа по заданному шаблону
    float max_value = max_num_by_pattern(n, matrix);
    printf("Максимальное число по шаблону: %.2f\n", max_value);
}

int main() {
    // Проверка 
    // assert(max_num_by_pattern(3, (float[N][N])
    // {{1.0f, 2.0f, 3.0f}, 
    // {4.0f, 5.0f, 6.0f}, 
    // {7.0f, 8.0f, 9.0f}}) == 5.0f);
    
    solve();
    return 0;
}