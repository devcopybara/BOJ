#include <stdio.h>

void swap(int* a,int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a>b) swap(&a, &b);

    if(b>c) {
        swap(&b, &c);
        if(a>b) swap(&a, &b);
    }

    printf("%d %d %d",a, b, c);

    
}