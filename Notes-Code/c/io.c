#include <stdio.h>

int main() {
    int a1, a2, sum;
    printf("Enter first integer: ");
    scanf("%d", &a1);
    printf("Enter second integer: ");
    scanf("%d", &a2);
    sum = a1 + a2;
    printf("Sum is %d\n", sum);
    return 0;
}