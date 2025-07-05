#include <stdio.h>
#include <string.h>

// для работы со списками
#include "../modules/str_lists.h"

void Solve() {
    // просит пользователя ввести строку
    char input[1024];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    char word[128];
    int word_len = 0; // длина текущего слова
    Node * head = create_list(""); // указатель на голову списка
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i]; // текущий символ
        if (c == ' ') {
            if (word_len > 0) {
                word[word_len] = '\0'; // завершает слово
                add_node(head, word); // добавляет слово в список
                word_len = 0;
            }
        } else {
            // добавляет символ к текущему слову
            word[word_len] = c;
            word_len++;
        }
    }
    // добавляет последнее слово, если оно есть
        if (word_len) {
            word[word_len] = '\0'; // завершает слово
            add_node(head, word); // добавляет слово в список
        }
    // если слов больше одного и их количество нечетное
    if (list_length(head) > 1 && list_length(head) % 2 == 1) {
        // удаляет первое слово
        delete_pos(head, 1);
    }
    print_list(head); // печатает список
}

int main() {
    Solve();
    return 0;
}