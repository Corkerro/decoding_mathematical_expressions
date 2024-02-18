#include "../inc/header.h"

bool mx_is_available_number(const char *str) {
    if (str[0] == '\0')
        return false;

    for (int i = 0; i < mx_strlen(str); ++i) {
        if (!mx_isdigit(str[i]) && str[i] != '?')
            return false;
    }

    return true;
}

bool mx_is_available_operator(const char *str) {
    if (mx_strlen(str) != 1)
        return false;

    const char available_operators[5] = { '+', '-', '*', '/', '?'};
    for (int i = 0; i < 5; ++i) {
        if(str[0] == available_operators[i])
            return true;
    }
    return false;
}

char *mx_clear_data(const char *string) {
    int length = mx_strlen(string);
    int start_index = 0;
    int end_index = length - 1;

    // Находим индекс первого непробельного символа с начала строки
    while (mx_isspace(string[start_index]) && start_index < length) {
        start_index++;
    }

    // Находим индекс последнего непробельного символа с конца строки
    while (mx_isspace(string[end_index]) && end_index >= 0) {
        end_index--;
    }

    // Вычисляем длину новой строки без пробелов в начале и конце
    int new_length = end_index - start_index + 1;

    // Создаем новую строку без пробелов в начале и конце
    char *result = (char *)malloc((new_length + 1) * sizeof(char)); // +1 для символа '\0' в конце строки
    if (result == NULL) {
        mx_printerr("Memory allocation failed\n");
        exit(-1);
    }

    // Копируем символы из исходной строки без пробелов в начале и конце
    for (int i = 0; i < new_length; ++i) {
        result[i] = string[start_index + i];
    }
    result[new_length] = '\0'; // Добавляем символ '\0' в конец новой строки

    return result;
}

