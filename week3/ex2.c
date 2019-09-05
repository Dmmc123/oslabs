#include <stdio.h>

void bubble_sort(int [], int);
void print_array(int [], int);

int main(){
    int a[] = {1, 6, 101, 4, 100, 2, 10, 15, 68, 2};
    int n = sizeof(a)/sizeof(int);
    print_array(a, n);
    bubble_sort(a, n);
    print_array(a, n);
    return 0;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
