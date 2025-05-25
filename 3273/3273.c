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

int occur[1000001];
int main(void) {
    int n;
    IntInput(&n);

    int a;
    int minvalue = 1000000, maxvalue = 0;
    for(int i = 0; i < n; i++) {
        IntInput(&a);
        occur[a]++;

        minvalue = MIN(minvalue, a);
        maxvalue = MAX(maxvalue, a);
    }

    int x;
    IntInput(&x);

    int ans = 0;
    int start = MAX(minvalue, x - 1000000), end = MIN(maxvalue + 1, (x + 1) / 2);
    for(int i = start; i < end; i++) {
        if(occur[i] && occur[x - i]) ans++;
    }
    IntPrint(ans);
}