#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the length of array: ");
    scanf("%d", &n);

    int * array = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) *(array + i) = i;
    for (int i = 0; i < n; i++) printf("%d%c", *(array + i), (i == n - 1) ? '\n' : ' ');

    free(array);

    return 0;
}
