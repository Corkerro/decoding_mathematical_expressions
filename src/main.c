#include "../inc/header.h"

void calculate_number(t_data *data, t_number_status *number_status);

char *check_number_status(char *string, bool *is_positive);
void loop_calculate_number(t_data *data, t_number_status *number_status, int global_size,
                           const char *merged_strings, int number_of_questions);

int main(int argc, char **argv) {
    t_errors errors;
    init_errors(&errors);

    // Проверка что введенно именно 4 символа
    if (argc != 5)
        errors.error_with_program_call();

    t_number_status number_status;
    t_data data = {check_number_status(mx_clear_data(argv[1]), &number_status.is_operand_1_positive),
                   check_number_status(mx_clear_data(argv[3]), &number_status.is_operand_2_positive),
                   mx_clear_data(argv[2]),
                   check_number_status(mx_clear_data(argv[4]), &number_status.is_result_positive)};

    // Валидация
    if (!mx_is_available_operator(data.operator))
        errors.error_with_operator(data.operator);
    if (!mx_is_available_number(data.operand_1))
        errors.error_with_operand(data.operand_1);
    if (!mx_is_available_number(data.operand_2))
        errors.error_with_operand(data.operand_2);
    if (!mx_is_available_number(data.result))
        errors.error_with_result(data.result);

    calculate_number(&data, &number_status);

    free(data.operand_1);
    free(data.operand_2);
    free(data.result);
    free(data.operator);

    return 0;
}

void calculate_number(t_data *data, t_number_status *number_status) {
    int global_size = mx_strlen(data->operand_1) + mx_strlen(data->operand_2) + mx_strlen(data->result);
    char *merged_strings = (char *)malloc(global_size + 1);
    const char operator = data->operator[0];

    // Проверка выделения памяти
    if (merged_strings == NULL) {
        mx_printerr("Memory allocation failed\n");
        exit(-1);
    }

    int number_of_questions = 0;

    mx_init_merged_strings(data, merged_strings, &number_of_questions);

    if (operator == '?') {
        const char available_operators[4] = { '+', '-', '*', '/'};
        for (int i = 0; i < 4; ++i) {
            data->operator[0] = available_operators[i];
            loop_calculate_number(data, number_status, global_size, merged_strings, number_of_questions);
        }
    } else {
        loop_calculate_number(data, number_status, global_size, merged_strings, number_of_questions);
    }

    // Освобождение выделенной памяти
    free(merged_strings);
}

void loop_calculate_number(t_data *data, t_number_status *number_status, int global_size,
                           const char *merged_strings, int number_of_questions) {
    for (long long new_number = 0; new_number < mx_pow(10, number_of_questions); ++new_number) {
        long long my_number = 0;
        int questions_counter = 0;
        for (int i = 0; i < global_size; ++i) {
            if (merged_strings[i] == '?') {
                my_number += (new_number / mx_pow(10, number_of_questions - questions_counter - 1) % 10)
                             * mx_pow(10, global_size - i - 1);
                questions_counter++;
            } else {
                my_number += mx_chartoint(merged_strings[i]) * mx_pow(10, global_size - i - 1);
            }
        }
        mx_print_number(data, number_status, &my_number);
    }
}

char *check_number_status(char *string, bool *is_positive) {
    char *new_value;

    if ((mx_strlen(string) == 1 && string[0] == '-') || (mx_strlen(string) > 1 && (string[1] != '1' && string[1] != '2'
                                                                                   && string[1] != '3' && string[1] != '4' && string[1] != '5' && string[1] != '6' && string[1] != '7'
                                                                                   && string[1] != '8' && string[1] != '9' && string[1] != '0' && string[1] != '?'))) {
        return string;
    }

    if (string[0] == '-') {
        int len = mx_strlen(string);
        new_value = (char *)malloc(len); // Выделение памяти
        if (new_value == NULL) {
            // Обработка ошибки выделения памяти
            mx_printerr("Memory allocation failed\n");
            exit(-1);
        }
        *is_positive = false;
        for (int i = 1; i < len; i++) {
            new_value[i - 1] = string[i];
        }
        new_value[len - 1] = '\0'; // Добавляем нулевой символ в конец новой строки
    } else {
        int len = mx_strlen(string);
        new_value = (char *)malloc(len + 1); // Выделение памяти на 1 символ больше для нулевого символа
        if (new_value == NULL) {
            // Обработка ошибки выделения памяти
            mx_printerr("Memory allocation failed\n");
            exit(-1);
        }
        *is_positive = true;
        for (int i = 0; i < len; i++) {
            new_value[i] = string[i];
        }
        new_value[len] = '\0'; // Добавляем нулевой символ в конец новой строки
    }
    free(string);
    return new_value;
}

