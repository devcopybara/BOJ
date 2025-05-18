#include <stdio.h>

int main(void) {
    int sum = 0, min = 100, a;

    for(int i = 0; i < 7; i++) {
        scanf("%d", &a);

        if(a & 1) {
            sum += a;
            if(min > a) min = a;
        }
    }

    if(sum) {
        printf("%d\n%d", sum, min);
    }
    else {
        printf("-1");
    }
}