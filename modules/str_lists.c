#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// объявление синонима типа
typedef struct str_Node Node;

// структура списка
struct str_Node {
    char Data[128];
    Node * Next;
};

// Создаёт список с головой со значением value
// Возвращает голову списка, по которой можно обращаться
// к самому списку.
Node * create_list(char value[128]) {
    Node * head = malloc(sizeof(Node)); // выделение памяти
    strcpy(head->Data, value); // копирование строки в голову
    head->Next = NULL;
    return head;
}
// Создание нового узла со значением value
// В конце списка
void add_node(Node* head, char value[128]) {
    // переход к концу списка
    while (head->Next != NULL) {
        head = head->Next;
    }
    // выделение памяти и добавление нового узла
    Node * new_node = malloc(sizeof(Node));
    strcpy(new_node->Data, value); // копирование строки в новый узел
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

// Функция для печати списка
void print_list(Node* head) {
    if (head->Data[0] == '\0') {
        head = head->Next; // если голова пустая, переходит к следующему
    }
    while (head != NULL) {
        printf("%s ", head->Data);
        head = head->Next;
    }
    printf("\n");
}

// Функция для подсчёта длины списка
// Возвращает количество узлов в списке
// Если голова пустая, то её пропускает
int list_length(Node* head) {
    int length = 0;
    if (head->Data[0] == '\0') {
        head = head->Next; // если голова пустая, переходит к следующему
    }
    while (head != NULL) {
        length++;
        head = head->Next;
    }
    return length;
}