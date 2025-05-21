#include <stdio.h>

int main(void) {
    int n, a, y = 0, m = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);

        y += 10 + (a / 30) * 10;
        m += 15 + (a / 60) * 15;
    }

    if(m > y) printf("M %d", m);
    else if(y < m) printf("Y %d", y);
    else printf("Y M %d", y);
}