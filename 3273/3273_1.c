#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void IntInput(int* var) {
    int val = 0;
    char ch = getchar();

    while(ch >= '0' && ch <= '9') {
        val = val * 10 + ch - '0';
        ch = getchar();
    }
    *var = val;
}

void IntPrint(int val) {
    char buf[7];

    int i = 0;
    do {
        buf[i++] = val % 10;
        val /= 10;
    }while(val);

    while(i--) {
        putchar('0' + buf[i]);
    }
}

int a[1000001];
int occur[2000001];
int main(void) {
    int n;
    IntInput(&n);

    for(int i = 0; i < n; i++) IntInput(&a[i]);

    int x;
    IntInput(&x);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(x - a[i]> 0 && occur[x - a[i]]) ans++;
        occur[a[i]] = 1;
    }
    IntPrint(ans);
}