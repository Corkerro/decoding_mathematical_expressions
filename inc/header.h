#pragma once

#ifndef HEADER_H
#define HEADER_H


// 🅸🅽🅲🅻🆄🅳🅴🆂
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


// 🆂🆃🆁🆄🅲🆃🆂
typedef struct {
    void (*error_with_program_call)(void);
    void (*error_with_operand)(const char *error);
    void (*error_with_operator)(const char *error);
    void (*error_with_result)(const char *error);
} t_errors;

typedef struct {
    char *operand_1;
    char *operand_2;
    char *operator;
    char *result;
} t_data;

typedef struct {
    bool is_operand_1_positive;
    bool is_operand_2_positive;
    bool is_result_positive;
} t_number_status;

typedef struct {
    long long first_number;
    long long second_number;
    char operator;
    long long result;
} t_answer;


// 🅿🆁🅾🆃🅾🆃🆈🅴🅿🆂
void mx_printstr(const char *s);
bool mx_isdigit(int c);
void init_errors(t_errors *errors);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
bool mx_isspace(char c);
int mx_atoi(const char *str);
long mx_pow(int n, long pow);
void mx_printchar(char c);
void mx_print_long_long(long long n);

// mx_validation.c
bool mx_is_available_number(const char *str);
bool mx_is_available_operator(const char *str);
char *mx_clear_data(const char *string);

// mx_basic.c
int mx_chartoint(char c);
void mx_print_answer(t_answer *answer);
void mx_init_merged_strings(t_data *data, char *merged_strings, int *number_of_questions);
void mx_print_number(t_data *data, t_number_status *number_status, long long *my_number);

#endif // HEADER_H
