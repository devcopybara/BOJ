#include <stdio.h>

int main(void) {
    int sum = 0, a[5];

    for(int i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for(int i = 0; i < 3; i++) {
        for(int j = i; j < 5; j++) {
            if(a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    printf("%d\n%d", sum / 5, a[2]);
}