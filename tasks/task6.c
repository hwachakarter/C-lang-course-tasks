#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // инициализация генератора случайных чисел

    const unsigned int N = 1024; // максимальный размер массива

    float a[N]; // массив чисел а
    int counter = 0; // счетчик для повторяюищихся чисел

    unsigned int n = 0; // количество чисел в массиве

    printf("Введите количество чисел в массиве: ");
    scanf("%u", &n);

    for (unsigned int i = 0; i < n; i++) {
        // заполнение массива случайными числами от -1.00 до 1.00
        a[i] = (float)(rand() % 201 - 100) / 100.0f;
    }

    // вывод массива
    printf("Сгенерированный массив:\n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    // выполнение задачи
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int current = 0; current < n; current++) {
            if (i != current && fabs(a[i] - a[current]) < 0.001f) { 
                // если числа равны с точностью до 0.001
                
                a[i] = 999999.0f; // меняем число на огромное значение
                counter++;
                break; // выходим из внутреннего цикла, так как нашли повторение
            }
        }
    }

    // вывод результата
    printf("\n\nКоличество повторяющихся чисел: %d\n", counter);
}