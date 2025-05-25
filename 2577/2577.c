#include <stdio.h>

int freq[10];
int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int abc = a * b * c;
    while(abc) {
        freq[abc % 10]++;
        abc /= 10;
    }

    for(int i = 0; i < 10; i++) printf("%d\n", freq[i]);
}