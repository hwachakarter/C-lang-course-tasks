#include <stdio.h>
#include <math.h>
#include <string.h>

// Функция для записи строки в файл
// string - строка, которую нужно записать
// file_path - путь к файлу, в который нужно записать строку
void string_to_file(char string[], char file_path[]) {
    FILE * f = fopen(file_path, "w");
    fprintf(f, "%s", string);
    fclose(f);
}

// Функция для поиска совершенных квадратов в файле
// input_file - входной файл, в котором нужно искать совершенные квадраты
// output_file - выходной файл, в который нужно записать найденные совершенные квадраты
// Возвращает 0, если прошло успешно, 1 - если файл не найден
int parse_for_perfect_squares(char input_file[], char output_file[]) {
    FILE * input = fopen(input_file, "r");
    if (input == NULL) {
        return 1; // файл не найден
    }
    FILE * output = fopen(output_file, "w");
    float cur_num;
    while (!feof(input)) {
        fscanf(input, "%f", &cur_num);
        if ((int)(cur_num) == ((int)(sqrtf(cur_num)) * (int)(sqrtf(cur_num)))) {
            fprintf(output, "%.2f\n", cur_num);
        }
    }
    return 0; // прошло успешно
}

// Функция для поиска однофамильцев
// Возвращает 0, если однофамильцы найдены, 1 - если не найдены
// или файл не найден
int find_same_surname(char input_file[]) {
    FILE * input = fopen(input_file, "r");
    if (input == NULL) {
        return 1; // файл не найден
    }
    // Открывает второй раз тот же файл для сравнения
    FILE *input2 = fopen(input_file, "r");
    
    char surname[256];
    char name[256];
    char class_name[256];
    int found = 0;
    int pos = 0; // позиция в файле
    int pos2 = 0; // позиция во втором файле

    while (!feof(input)) {
        pos2 = 0; // сбрасывает позицию во втором файле
        fscanf(input, "%s %s %s", name, surname, class_name);
        fseek(input2, 0, SEEK_SET); // сбрасывает указатель на начало второго файла
        char name2[256], surname2[256], class_name2[256];
        while (!feof(input2)) {
            fscanf(input2, "%s %s %s", name2, surname2, class_name2);
            // Проверяет, что фамилии совпадают, но имена разные
            if (strcmp(surname, surname2) == 0 && pos != pos2) {
                found = 1;
                break;
            }
            pos2++;
        }

        if (found) {
            fclose(input);
            return 0; // однофамильцы найдены
        }
        pos++;
    }

    fclose(input);
    return 1; // однофамильцы не найдены
}