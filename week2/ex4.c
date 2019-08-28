#include <stdio.h>

void swap(int * a, int * b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);
    printf("Before swap\na = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap\na = %d, b = %d", a, b);
    return 0;
}