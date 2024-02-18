#include "../inc/header.h"

void mx_printchar(char c);

void mx_print_long_long(long long n) {
    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    if (n >= 10) {
        mx_print_long_long(n / 10);
    }

    mx_printchar(n % 10 + '0');
}

