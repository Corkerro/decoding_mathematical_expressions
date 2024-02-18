#include "../inc/header.h"

void error_with_program_call(void) {
    mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
    exit(-1);
}
void error_with_operand(const char *error) {
    mx_printerr("Invalid operand: ");
    mx_printerr(error);
    mx_printerr("\n");
    exit(-1);
}
void error_with_operator(const char *error) {
    mx_printerr("Invalid operation: ");
    mx_printerr(error);
    mx_printerr("\n");
    exit(-1);
}
void error_with_result(const char *error) {
    mx_printerr("Invalid result: ");
    mx_printerr(error);
    mx_printerr("\n");
    exit(-1);
}
void init_errors(t_errors *errors) {
    errors->error_with_program_call = error_with_program_call;
    errors->error_with_operand = error_with_operand;
    errors->error_with_operator = error_with_operator;
    errors->error_with_result = error_with_result;
}

