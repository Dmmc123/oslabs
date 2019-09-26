#include <stdio.h>
#include <signal.h>

int FLAG;

void myFun() {
    printf("You've just 'ctr+c'-ed the program\n");
    FLAG = 1;
}

int main (void) {
    signal(SIGINT, myFun);
    while(!FLAG);
    return 0;
}