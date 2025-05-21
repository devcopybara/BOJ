#include <stdio.h>

void input(int* a) {
    *a = 0;
    char ch = getchar();
    while (ch >= '0' && ch <= '9') {
        *a = *a * 10 + (ch - '0');
        ch = getchar();
    }
}

void output(int a) {
    char buf[5];

    int i = 0;

    while(a) {
        buf[i++] = '0' + a % 10;
        a /= 10;
    }

    while(i--) {
        putchar(buf[i]);
    }
    putchar('\n');
}

int main(void) {
    int n, a, b;
    
    input(&n);

    for(int i = 0; i < n; i++) {
        input(&a);
        input(&b);
        
        output(a + b);
    }
}