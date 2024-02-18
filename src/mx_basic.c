#include "../inc/header.h"
#include <stdio.h>

int mx_chartoint(char c) {
    return c - '0';
}
void mx_print_answer(t_answer *answer) {
    mx_print_long_long(answer->first_number);
    mx_printchar(' ');
    mx_printchar(answer->operator);
    mx_printchar(' ');
    mx_print_long_long(answer->second_number);
    mx_printstr(" = ");
    mx_print_long_long(answer->result);
    mx_printchar('\n');
}
void mx_init_merged_strings(t_data *data, char *merged_strings, int *number_of_questions) {
    // Копирование содержимого первого массива в новую строку
    for (int i = 0; data->operand_1[i] != '\0'; i++) {
        merged_strings[i] = data->operand_1[i];
        if (data->operand_1[i] == '?')
            (*number_of_questions)++;
    }

    // Копирование содержимого второго массива в новую строку
    for (int i = 0; data->operand_2[i] != '\0'; i++) {
        merged_strings[mx_strlen(data->operand_1) + i] = data->operand_2[i];
        if (data->operand_2[i] == '?')
            (*number_of_questions)++;
    }

    // Копирование содержимого третего массива в новую строку
    for (int i = 0; data->result[i] != '\0'; i++) {
        merged_strings[mx_strlen(data->operand_1) + mx_strlen(data->operand_2) + i] = data->result[i];
        if (data->result[i] == '?')
            (*number_of_questions)++;
    }

    merged_strings[mx_strlen(data->operand_1) + mx_strlen(data->operand_2) + mx_strlen(data->result)] = '\0';
}
void mx_print_number(t_data *data, t_number_status *number_status, long long *my_number){
    long long frist_number = *my_number / mx_pow(10, mx_strlen(data->operand_2) + mx_strlen(data->result));
    long long second_number = *my_number / mx_pow(10, mx_strlen(data->result)) % mx_pow(10, mx_strlen(data->operand_2));
    long long result = *my_number % mx_pow(10, mx_strlen(data->result));

    if (number_status->is_operand_1_positive == false)
        frist_number *= -1;
    if (number_status->is_operand_2_positive == false)
        second_number *= -1;
    if (number_status->is_result_positive == false)
        result *= -1;



    t_answer answer = {frist_number, second_number, data->operator[0], result};

    switch (data->operator[0]) {
        case '+':
            if (frist_number + second_number == result) {
                mx_print_answer(&answer);
            }
            break;
        case '-':
            if (frist_number - second_number == result) {
                mx_print_answer(&answer);
            }
            break;
        case '*':
            if (frist_number * second_number == result) {
                mx_print_answer(&answer);
            }
            break;
        case '/':
            if (second_number != 0 && frist_number / second_number == result) {
                mx_print_answer(&answer);
            }
            break;
        default:
            break;
    }
}

