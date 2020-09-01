#include <stdio.h>

#include "shared.h"

int main(void) {
    unsigned int a = 7;
    unsigned int b = 4;
    unsigned int add_result, sub_result, mult_result;
    add_result = add(a, b);
    sub_result = subtract(a, b);
    mult_result = mult(a, b);
    printf("\n %u + %u = %u \n", a, b, add_result);
    printf("\n %u - %u = %u \n", a, b, sub_result);
    printf("\n %u * %u = %u \n", a, b, mult_result);
    return 0;
}