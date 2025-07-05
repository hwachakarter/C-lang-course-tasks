#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// для файлов
#include "../modules/files.h"

// выполеяет задачу
void solve(char input[], char output[]) {
    if (parse_for_perfect_squares(input, output) == 1) {
        puts("файл не найден");
    } else {
        puts("Успешно.");
    }
}

// argc - количество аргументов
// argv - массив аргументов
// argv[0] - имя программы
// argv[1] - входной файл
// argv[2] - выходной файл
int main(int argc, char * argv[]) {
    if (argc == 1) {
        // если аргументов нет
        printf("%s", "./task10_1 <input_file> <output_file>\n");
        return 1;
    } else
    if (argc == 3) {
        // если аргументы есть и верное количество
        solve(argv[1], argv[2]);
        return 0;
    } else {
        // если аргументов больше или меньше 2
        printf("%s", "Wrong argument count\n");
        printf("%s", "./task10_1 <input_file> <output_file>\n");
        return 1;
    }
}