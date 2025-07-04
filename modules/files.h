#include <stdio.h>
#include "lists.h"

// возвращает float список из файла file_path
Node * parse_float_f_to_list(char file_path[]);

// Функция для записи float списка в файл
// Возвращает 0 при успешной записи, 1 при ошибке открытия файла
int write_float_list_to_f(Node * list, char file_path[]);