#include <stdio.h>

int main(void) {
    int a, cnt;

    for(int i = 0; i < 3; i++) {
        cnt = 0;
        
        for(int i = 0; i < 4; i++) {
            scanf("%d", &a);
            cnt += a;
        }

        printf("%c\n", cnt == 4 ? 'E' : 'D' - cnt);
    }
}