#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    float Data;
    Node * Next;
};

// объявление синонима типа
typedef struct Node Node;

// Создаёт список с головой со значением value
// Возвращает голову списка, по которой можно обращаться
// к самому списку.
Node * create_list(float value);

// Создание нового узла со значением value
// В конце списка
void add_node(Node* head, float value);

// Удаляет узел на позиции pos.
// Индексы начинаются с 0 - головы списка.
// Возвращает голову, может быть полезно,
// Если голова была обновлена.
Node * delete_pos(Node* head, int pos);

// Выводит все значения списка через пробел.
void print_list(Node* head);

// Очищает список из памяти
void free_list(Node* head);