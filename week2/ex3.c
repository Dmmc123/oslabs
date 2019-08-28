#include <stdio.h>

void print_char(int n, int c) {
    for (int i = 0; i < n; i++) putchar(c);
}

void print_triangle_ex3(int n) {
    for (int i = 0; i < n; i++) {
        print_char(n-i-1, ' ');
        print_char(2*i+1, '*');
        if (i != n-1) putchar('\n');
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    print_triangle_ex3(n);
    return 0;
}