#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a[3];

    for(int i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            if(a[i] > a[j]) swap(a + i,a + j);
        }
    }
    
    for(int i = 0; i < 3; i++) {
        printf("%d ", a[i]);
    }
}