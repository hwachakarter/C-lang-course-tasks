#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand( time(NULL) ); // инициализация генератора случайных чисел

    const unsigned int N = 1024; // максимальный размер массива

    float a[N]; // массив чисел а

    unsigned int n = 0; // количество чисел в массиве

    printf("Введите количество чисел в массиве: ");
    scanf("%u", &n);

    // заполнение массива случайными числами от -10 до 10
    for (unsigned int i = 0; i < n; i++) {
        a[i] = (float)(rand() % 201 - 100) / 10.0f;
    }

    // вывод массива
    printf("Сгенерированный массив:\n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%.1f ", a[i]);
    }

    // выполнение задачи
    for (unsigned int i = 0; i < n; i++) {
        if (a[i] < 0) {
            // если число отрицательное
            a[i] += 0.5f;
        } else {
            // если число положительное
            a[i] = 0.1f;
        }
    }

    // вывод результата
    printf("\n\nРезультат:\n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%.1f ", a[i]);
    }

    printf("\n");
    return 0;
}