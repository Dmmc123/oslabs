#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_OP 100

char BUF[MAX_OP];

int main() {
    while (1) {
        printf("Type the command. To terminate type 'exit'\n");
        fgets(BUF, MAX_OP, stdin);
        if (strcmp("exit\n", BUF) == 0) break;
        else system(BUF);
    }
    return 0;
}
