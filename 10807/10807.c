#include <stdio.h>

int occur[201];
int main(void) {
    int n;
    scanf("%d", &n);

    int a;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        occur[a + 100]++;
    }

    int v;
    scanf("%d", &v);

    printf("%d", occur[v + 100]);
}