#include <stdio.h>

unsigned int strlen(char* s) {
    int len = 0;

    while(*s++ != '\0') {
        len++;
    }

    return len;
}

int main(void) {
    char s[1000];
    scanf("%s", s);

    int len = strlen(s);

    for(char c = 'a'; c <= 'z'; c++) {
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(s[i] == c) cnt++;
        }
        printf("%d ", cnt);
    }
}