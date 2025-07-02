#include <stdio.h> // для ввода-вывода
#include <math.h> // для математических функций
// для рандомных чисел
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // инициализация генератора случайных чисел

    const unsigned int N = 1024; // максимальный размер массива

    float a[N]; // массив чисел а
    int counter = 0; // счетчик для неповторяюищихся чисел

    unsigned int n = 0; // количество чисел в массиве

    printf("Программа считает количество неповторяющихся чисел в массиве\n");
    printf("Введите количество чисел в массиве: ");
    scanf("%u", &n);

    a[0] = 1;
    a[1] = 1;

    for (unsigned int i = 2; i < n; i++) {
        // заполнение массива начиная с 2 случайными числами от -1.00 до 1.00
        a[i] = (float)(rand() % 201 - 100) / 100.0f;
    }

    // вывод массива
    printf("Сгенерированный массив:\n");
    for (unsigned int i = 0; i < n; i++) {
        printf("%.2f ", a[i]);
    }

    // выполнение задачи
    for (unsigned int i = 0; i < n; i++) {
        int is_unique = 1; // флаг для проверки уникальности числа
        for (unsigned int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                is_unique = 0; // число не уникально
                counter--;
                break;
            }
        }
        if (is_unique) {
            counter++;
        }
    }


    // вывод результата
    printf("\n\nКоличество неповторяющихся чисел: %d\n", counter);
}