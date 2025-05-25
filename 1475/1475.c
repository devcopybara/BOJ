#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int freq[10];
int main(void) {
    int n;
    scanf("%d", &n);

    while(n) {
        freq[n % 10]++;
        n /= 10;
    }

    freq[6] = (freq[6] + freq[9] + 1) / 2;
    freq[9] = 0;

    int ans = 0;
    for(int i = 0; i < 9; i++) ans = MAX(ans, freq[i]);
    printf("%d", ans);
}