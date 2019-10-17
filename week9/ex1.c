#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define UCHAR_MAX 255

int find_page(int a[], int N, int page) {
    int ans = -1;
    for (int i = 0; i < N; i++) if (a[i] == page) ans = i;
    return ans;
}

void shift(unsigned char a[], int N) {
    for (int i = 0; i < N; i++) a[i] >>= 1;
}

int find_min_age(unsigned char a[], int N) {
    unsigned char min = UCHAR_MAX;
    int ans = -1;
    for (int i = 0; i < N; i++) if (a[i] < min) {
        min = a[i];
        ans = i;
    }
    return ans;
}

int main() {
    // the parameter
    int N = 100;

    int hits, misses;
    hits = misses = 0;
    int values[N];
    for (int i = 0; i < N; i++) values[i] = -1;
    unsigned char counts[N];
    for (int i = 0; i < N; i++) counts[i] = 0;
    int k = 0;

    FILE * input = fopen("Lab 09 input.txt", "r");
    int c, page;
    page = 0;
    while ((c = getc(input)) != EOF) {
        if (isdigit(c)) {
            page = page * 10 + c - '0';
        }
        else {
            // now page is the number of page we are working with
            int page_index = find_page(values, k, page);
            if (page_index == -1) {
                if (values[k] == -1) {
                    values[k] = page;
                    shift(counts, k);
                    counts[k] |= (1<<7);
                    k = (k + 1 > N - 1) ? (N - 1) : (k + 1) ;
                }
                else {
                    int i_new = find_min_age(counts, k);
                    values[i_new] = page;
                    shift(counts, k);
                    counts[i_new] = (1<<7);
                }
                misses++;
            }
            else {
                shift(counts, k);
                counts[page_index] |= (1<<7);
                hits++;
            }
            page = 0;
        }
    }
    fclose(input);

    printf("Hits: %d\nMisses: %d\nRatio: %f", hits, misses, (float) hits / misses);

    // Hits/Misses
    // N = 10: 10/990
    // N = 50: 50/950
    // N = 100: 92/908

    return 0;
}