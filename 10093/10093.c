#include <stdio.h>

int main(void) {
    unsigned long long a, b, t;
    scanf("%llu %llu", &a, &b);

    if(a > b) {
        t = a;
        a = b;
        b = t;
    }

    printf("%llu\n", b != a ? b - a - 1 : 0);

    for(unsigned long long i = a + 1; i < b; i++) printf("%llu ", i);
}