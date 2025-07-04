#include <stdlib.h>
#include <time.h>
#include <math.h>
// для списков
#include "../modules/lists.h"

// Функция создания рандомного списка
Node * create_random_list() {
    // создание списка с головой
    Node * list = create_list(rand() % 100 - 50);
    // заполнение списка
    for (int i = 0; i < 10; i++) {
        add_node(list, rand() % 100 - 50);
    }
    return list; // возврат списка
}

// Функция решения задачи
float solve() {
    // создание рандомного списка
    Node * list = create_random_list();
    Node * head = list;
    // вывод списка для отладки
    print_list(list);
    // объявление ответа
    float answer = 0.0f;
    // счёт ответа пока список не закончится
    while (head != NULL) {
        // fabsf - модуль числа float
        answer += fabsf(head->Data);
        head = head->Next;
    }
    return answer;
}

int main() {
    printf("Ответ: %.02f", solve()); // вывод ответа
    return 0;
}