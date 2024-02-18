#include "../inc/header.h"

long mx_pow(int n, long pow) {
    if (pow == 0 && n != 0)
        return 1;
    else
        return n * mx_pow(n, pow - 1);
}

