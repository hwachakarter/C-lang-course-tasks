#include <stdio.h>
#include "lists.h"

// возвращает float список из файла file_path
Node * parse_float_f_to_list(char file_path[]) {
    FILE * f = fopen(file_path, "r");
    Node * list;
    float cur_num;
    // обработка первого элемента
    fscanf(f, "%f", &cur_num);
    list = create_list(cur_num);
    // обработка элементов пока не закончится файл
    while (!feof(f)) {
        fscanf(f, "%f", &cur_num);
        add_node(list, cur_num);
    }
    return list;
}

// Функция для записи float списка в файл
// Возвращает 0 при успешной записи, 1 при ошибке открытия файла
int write_float_list_to_f(Node * list, char file_path[]) {
    FILE * f = fopen(file_path, "w");
    if (f == NULL) {
        return 1; // ошибка открытия файла
    }
    Node * head = list;
    while (head != NULL) {
        fprintf(f, "%.02f ", head->Data);
        head = head->Next;
    }
    fclose(f);
    return 0; // успешно записано
}