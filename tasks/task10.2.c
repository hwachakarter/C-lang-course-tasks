#include <stdio.h>
#include <string.h>
#include "../modules/files.h"

void Solve() {
    // Проверка на наличие однофамильцев
    if (find_same_surname("files/f.txt") == 0) {
        puts("Однофамильцы найдены.");
    } else {
        puts("Однофамильцы не найдены.");
    }
}

int main() {
    Solve(); // Выполнение задачи
    return 0; // Возврат 0 для успешного завершения программы
}