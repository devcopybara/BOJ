#include <stdio.h>

#define ABS(a) ((a) >= 0 ? (a) : -(a))

char a[1001], b[1001];
int afreq[26], bfreq[26];
int ans;
int main(void) {
    scanf("%s %s", a, b);

    for(char* ch = a; *ch != '\0'; ch++) afreq[*ch - 'a']++;
    for(char* ch = b; *ch != '\0'; ch++) bfreq[*ch - 'a']++;

    for(int i = 0; i < 26; i++) {
        ans += ABS(afreq[i] - bfreq[i]);
    }
    printf("%d", ans);
}