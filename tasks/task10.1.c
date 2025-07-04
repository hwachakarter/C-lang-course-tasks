#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
// для файлов
#include "../modules/files.h"

// выполеяет задачу
Node * solve() {
    // получение списка из файла f.txt
    Node * list_f = parse_float_f_to_list("files/f.txt");
    Node * list_g;
    int g_created = 0; // флаг "создан ли список g"
    Node * head = list_f; // голова списка f
    while (head != NULL) {
        // проверка, является ли число в узле квадратом целого числа
        // sqrtf - извлечение корня из числа float
        if ((int)(head->Data) == 
        ((int)(sqrtf(head->Data)) * (int)(sqrtf(head->Data)))) {
            if (g_created) {
                add_node(list_g, head->Data);
            } else {
                list_g = create_list(head->Data);
                g_created = 1;
            }
        }
        head = head->Next; // переход к следующему узлу
    }
    free_list(list_f); // освобождение памяти списка f
    if (!g_created) {
        // если список g не был создан, то создаём пустой список
        // с головой со значением -1.0f
        return create_list(-1.0f);
    } else {
        return list_g;
    }
    
}


int main() {
    Node * list = solve();
    if (list->Data == -1.0f) {
        printf("Список квадратов пустой.\n");
        return 1;
    } else {
        // запись списка в файл g.txt
        write_float_list_to_f(list, "files/g.txt");
        printf("Файл g.txt записан.\n");
    }
    return 0;
}