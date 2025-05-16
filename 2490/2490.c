#include <stdio.h>

int main() {
    int a, cnt;

    for(int i = 0; i < 3; i++) {
        cnt = 0;
        
        for(int i = 0; i < 4; i++) {
            scanf("%d", &a);
            cnt += a;
        }

        if(cnt == 4) printf("E\n");
        else if(cnt == 3) printf("A\n");
        else if(cnt == 2) printf("B\n");
        else if(cnt == 1) printf("C\n");
        else printf("D\n");
    }
}