#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// объявление синонима типа
typedef struct Node Node;

// структура списка
struct Node {
    float Data;
    Node * Next;
};

// Создаёт список с головой со значением value
// Возвращает голову списка, по которой можно обращаться
// к самому списку.
Node * create_list(float value) {
    Node * head = malloc(sizeof(Node)); // выделение памяти
    head->Data = value;
    head->Next = NULL;
    return head;
}

// Создание нового узла со значением value
// В конце списка
void add_node(Node* head, float value) {
    // переход к концу списка
    while (head->Next != NULL) {
        head = head->Next;
    }
    // выделение памяти и добавление нового узла
    Node * new_node = malloc(sizeof(Node));
    new_node->Data = value;
    new_node->Next = NULL;
    head->Next = new_node;
}

// Удаляет узел на позиции pos.
// Индексы начинаются с 0 - головы списка.
// Возвращает голову, может быть полезно,
// Если голова была обновлена.
Node * delete_pos(Node* head, int pos) {
    // временная переменная для удаления (изначально голова)
    Node * temp = head;
    if (pos == 0) {
        // удаляет голову и возвращает новую
        head = head->Next;
        free(temp);
        return head;
    }
    // идёт до позиции перед той, что нужно удалить
    for (int i = 0; i < pos-1; i++) {
        if (head != NULL) {
            head = head->Next;
        } else {
            // если позиции нет выкидывает ошибку
            assert(1==0);
            return head;
        }
    }

    // проверка, что удаляемая позиция существует
    if (head->Next != NULL) {
        // присваивает узел для удаления
        temp = head->Next;
        // склеивает узлы по разные стороны от удаляемого
        head->Next = temp->Next;
        free(temp);
        return head; // чтобы не было предупреждения
    }
    // если позиции нет выкидывает ошибку
    assert(1==0);
}

// Получает значение узла на позиции pos.
// Индексы начинаются с 0 - головы списка.
// Возвращает значение узла.
float get_data(Node* head, int pos) {
    // идёт до позиции
    for (int i = 0; i < pos; i++) {
        if (head != NULL) {
            head = head->Next;
        } else {
            // если позиции нет выкидывает ошибку
            assert(1==0);
            return 0.0f; // чтобы не было предупреждения
        }
    }
    // проверка, что позиция существует
    if (head != NULL) {
        return head->Data; // возвращает значение узла
    }
    // если позиции нет выкидывает ошибку
    assert(1==0);
    return 0.0f; // чтобы не было предупреждения
}

// Выводит все значения списка через пробел.
void print_list(Node* head) {
    while (head != NULL) {
        printf("%.2f ", head->Data); // Вывод
        head = head->Next; // Переход
    }
    printf("\n");
}

// Очищает список из памяти
void free_list(Node* head) {
    Node * temp = head;
    while (head != NULL) {
        free(temp); // удаление узла
        head = head->Next; // переход к следующему узлу
        temp = head;
    }
}