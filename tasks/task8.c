#include <stdio.h>
#include <math.h>

int main() {
    // матрица n x n
    int N = 1024; // максимальный размер матрицы
    float matrix[N][N]; // объявление матрицы
    int n;
    int counter = 0; // счётчик положительных чисел
    
    printf("Введите размер матрицы n: ");
    scanf("%d", &n);

    if (n <= 0 || n > N) {
        printf("Размер матрицы должен быть в диапазоне от 1 до %d.\n", N);
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // заполнение матрицы по условию
            matrix[i][j] = sin((pow(i, 2) - pow(j, 2))/n);
        }
    }

    // счёт положительных чисел
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] > 0) {
                counter++;
            }
        }
    }

    // вывод матрицы
    printf("Сгенерированная матрица:");
    for (int i = 1; i <= n; i++) {
        printf("\n");
        for (int j = 1; j <= n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
    }
    printf("\n\nКоличество положительных чисел в матрице: %d\n", counter);
    return 0;
}