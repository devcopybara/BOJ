#include <stdio.h>

unsigned int strlen(char* s) {
    int len = 0;

    while(*s++ != '\0') {
        len++;
    }

    return len;
}

int freq[26];
int main(void) {
    char s[1000];
    scanf("%s", s);

    int len = strlen(s);

    for(int i = 0; i < len; i++) freq[s[i] - 'a']++;
    for(int i = 0; i < 26; i++) printf("%d ", freq[i]);
}