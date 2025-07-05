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
Node * create_list(char value[128]);

// Создание нового узла со значением value
// В конце списка
void add_node(Node* head, char value[128]);

// Удаляет узел на позиции pos.
// Индексы начинаются с 0 - головы списка.
// Возвращает голову, может быть полезно,
// Если голова была обновлена.
Node * delete_pos(Node* head, int pos);

// Функция для печати списка
void print_list(Node* head);

// Функция для подсчёта длины списка
// Возвращает количество узлов в списке
// Если голова пустая, то её пропускает
int list_length(Node* head);