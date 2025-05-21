#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a, b, c[21];
    for(int i = 1; i <= 20; i++) c[i] = i;

    for(int i = 0; i < 10; i++) {
        scanf("%d %d", &a, &b);

        for(int j = a, k = b; j < k; j++, k--) {
            swap(&c[j], &c[k]);
        }
    }

    for(int i = 1; i <= 20; i++) printf("%d ", c[i]);
}