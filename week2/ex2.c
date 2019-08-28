#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

void print_reverse(char s[]) {
    int n = strlen(s);
    for (int i = n - 2; i >= 0; i--) putchar(s[i]);
}
int main()
{
    char buffer[MAX_LINE];
    printf("Type your string: ");
    char * s = fgets(buffer, MAX_LINE, stdin);
    printf("Reversed: ");
    print_reverse(s);
    return 0;
}