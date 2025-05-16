#include <stdio.h>

#define MAX(a, b, c) (a >= b && a >= c ? a : b >= a && b >= c ? b : c)

int main() {
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);

    for(int i = 0; i < 3; i++) {
        for(int j  = i + 1; j < 3; j++) {
            if(a[i] > a[j]) { int t = a[i]; a[i] = a [j]; a[j] = t;};
        }
    }

    if(a[0] == a[2]) printf("%d", 10000 + a[0] * 1000);
    else if(a[0] == a[1] || a[1] == a[2]) printf("%d", 1000 + a[1] * 100);
    else printf("%d", a[2] * 100);
}