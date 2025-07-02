#include <stdio.h>
#include <math.h>

#include "../modules/matrix.h" // для матрицы

// Даны квадратная матрица А порядка n и вектор b c n элементами. Получить вектор: A^2b

int main() {
    int n;
    printf("Введите размер матрицы n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Размер матрицы должен быть положительным.\n");
        return 1;
    }

    int** matrix = generate_random_matrix(n, -10, 10); // Генерация случайной матрицы
    int* vector_b = (int*)malloc(n * sizeof(int)); // Выделение памяти для вектора b

    // Заполнение вектора b случайными числами
    for (int i = 0; i < n; i++) {
        vector_b[i] = rand() % 20 - 10; // Случайные числа от -10 до 9
    }

    // Вывод матрицы и вектора b
    print_matrix(n, matrix);
    printf("Вектор b: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vector_b[i]);
    }
    printf("\n");

    // Вычисление A^2b
    /*
    Умножение матрицы на вектор: для каждой строки матрицы A 
    умножаем её элементы на соответствующие элементы вектора b и суммируем.
    */

    // Вычисляем A^2 = A * A
    int** matrix_squared;
    // Выделение памяти для матрицы A^2
    matrix_squared = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        // Выделение памяти для каждой строки матрицы A^2
        matrix_squared[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                // Умножение матрицы A на саму себя
                matrix_squared[i][j] = matrix[i][k] * matrix[k][j];
            }
        }
    }

    // Вычисляем результат: (A^2) * b
    int* result_vector;
    // Выделение памяти
    result_vector = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Умножение строки матрицы A^2 на вектор b
            result_vector[i] += matrix_squared[i][j] * vector_b[j];
        }
    }

    printf("\n");

    // Выводим результат
    printf("Вектор A^2*b: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result_vector[i]);
    }
    printf("\n");

    return 0;
}