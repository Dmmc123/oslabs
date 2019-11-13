#include <stdio.h>
#include <ctype.h>

#define MARKED 1
#define NOT_MARKED 0
#define MAX_N 1000
#define MAX_M 100

int isLockFree(int a[], int N) {
    for (int i = 0; i < N; i++) {
        if (a[i] != MARKED) return 0;
    }
    return 1;
}

int main() {
    // input
    FILE * input = fopen("input.txt", "r");
    int c;

    int E[MAX_N];
    int ke = 0;
    int te = 0;
    while ((c = getc(input)) != '\n') {
        if (isdigit(c)) {
            te = 10 * te + c - '0';
        }
        else {
            E[ke++] = te;
            te = 0;
        }
    }

    getc(input);
    getc(input);

    int A[MAX_N];
    int ka = 0;
    te = 0;
    while ((c = getc(input)) != '\n') {
        if (isdigit(c)) {
            te = 10 * te + c - '0';
        }
        else {
            A[ka++] = te;
            te = 0;
        }
    }

    getc(input);
    getc(input);

    int C[MAX_M][MAX_N];
    int rc = 0, cc = 0;
    c = getc(input);
    while(1) {
        while (c != '\n') {
            if (isdigit(c)) {
                te = 10 * te + c - '0';
            }
            else {
                C[rc][cc++] = te;
                te = 0;
            }
            c = getc(input);
        }
        c = getc(input);
        rc++;
        if (c == 13 || c == '\n') break;
        cc = 0;
    }

    getc(input);

    int R[MAX_M][MAX_N];
    int rr = 0, cr = 0;
    c = getc(input);
    while(1) {
        while (c != '\n' && c != EOF) {
            if (isdigit(c)) {
                te = 10 * te + c - '0';
            }
            else {
                R[rr][cr++] = te;
                te = 0;
            }
            c = getc(input);
        }
        c = getc(input);
        if (c == 13 || c == '\n' || c == EOF) break;
        rr++;
        cr = 0;
    }
    R[rr++][cr++] = te;
    fclose(input);

    // algorithm
    int P = rr;
    int N = ke;

    int processes[P];
    for (int i = 0; i < P; i++) processes[i] = NOT_MARKED;

    int found = -1;
    while(found != 0) {
        found = 0;
        for (int i = 0; i < P; i++) {
            if (processes[i] == MARKED) continue;
            int valid = 1;
            for (int j = 0 ; j < N; j++) {
                if (R[i][j] > A[j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                //printf("process %d is done\n", i);
                for (int j = 0; j < N; j++) A[j] += C[i][j];
                processes[i] = MARKED;
                found = 1;
            }
        }
    }

    if (isLockFree(processes, P)) {
        printf("No Deadlock");
    }
    else {
        printf("Deadlock with processes ");
        for (int i = 0; i < P; i++) {
            if (processes[i] == NOT_MARKED) printf("%d ", i);
        }
    }

    return 0;
}