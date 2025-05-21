#include <stdio.h>

int main(void) {
    int a, maxVal, maxIdx = 1;

    scanf("%d", &maxVal);

    for(int i = 2; i <= 9; i++) {
        scanf("%d", &a);

        if(a > maxVal) maxVal = a, maxIdx = i;
    }

    printf("%d\n%d", maxVal, maxIdx);
}