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

void print_right_triangle(int n) {
    for (int i = 1; i < n + 1; i++) {
        print_char(i, '*');
        if (i != n) putchar('\n');
    }
}

void print_triangle(int n) {
    int middle = (n % 2) ? (n / 2 + 1) : (n / 2);
    int increment =  1 - n % 2;
    for (int i = 1; i < n + 1; i++) {
        print_char((i <= middle) ? (i) : (2*middle-i + increment), '*');
        if (i != n) putchar('\n');
    }
}

void print_rectangle(int n) {
    for (int i = 1; i < n + 1; i++) {
        print_char(n, '*');
        if (i != n) putchar('\n');
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    int type;
    printf("Choose a figure to print:\n1 - triangle from ex3\n2 - right triangle\n3 - triangle\n4 - rectangle\n");
    scanf("%d", &type);
    switch (type) {
        default: printf("No such type of figure");
        case 1: print_triangle_ex3(n); break;
        case 2: print_right_triangle(n); break;
        case 3: print_triangle(n); break;
        case 4: print_rectangle(n); break;

    }
    return 0;
}