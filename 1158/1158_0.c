#include <stdio.h>

const int MX = 5005;

int dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        dat[i] = i;
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    pre[1] = n;
    nxt[n] = 1;
    nxt[0] = 1;
    
    int size = n;
    int cur = 0;
    printf("<");
    while(size) {
        for(int i = 0; i < k; i++) cur = nxt[cur];
        
        printf("%d", dat[cur]);
        nxt[pre[cur]] = nxt[cur];
        pre[nxt[cur]] = pre[cur];
        size--;

        if(size) printf(", ");
    }
    printf(">");
}