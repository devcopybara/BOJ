#include <stdio.h>

int main(void) {
    int a, cnt;
    char res[6] = "DCBAE";

    for(int i = 0; i < 3; i++) {
        cnt = 0;
        
        for(int i = 0; i < 4; i++) {
            scanf("%d", &a);
            cnt += a;
        }

        printf("%c\n",res[cnt]);
    }
}