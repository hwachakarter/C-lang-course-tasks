#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    wchar_t str[256];
    int count = 0;

    // todo
    setlocale(LC_ALL, "");

    wprintf(L"Введите строку: ");
    // делением приводится размер одного элемента к wchar_t
    // sizeof(str) / sizeof(wchar_t) - количество элементов в массиве
    fgetws(str, sizeof(str) / sizeof(wchar_t), stdin);

    // проверяет, что первый символ 'б' или 'Б'
    if (str[0] == L'б' || str[0] == L'Б') {
        count++;
    }

    // перебирает строку начиная со второго символа
    for (int i = 1; str[i] != L'\0'; i++) {
        // проверяет, что текущий символ пробел и следующий символ 'б' или 'Б'
        if ((str[i-1] == ' ') && (str[i] == L'б' || str[i] == L'Б')) {
            count++;
        }
    }

    wprintf(L"Количество слов, начинающихся на букву 'б' в строке: %d\n", count);
    return 0;
}