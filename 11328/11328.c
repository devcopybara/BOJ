#include <stdio.h>
#include <string.h>

char a[1001], b[1001];
int afreq[26], bfreq[26];
int main(void) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s %s", a, b);

        memset(afreq, 0, sizeof(int) * 26);
        for(char* ch = a; *ch != '\0'; ch++) afreq[*ch - 'a']++;

        memset(bfreq, 0, sizeof(int) * 26);
        for(char* ch = b; *ch != '\0'; ch++) bfreq[*ch - 'a']++;

        int isPossible = 1;
        for(int i = 0; i < 26; i++) {
            if(afreq[i] != bfreq[i]) {
                isPossible = 0;
                break;
            }
        }
        if(isPossible) printf("Possible\n");
        else printf("Impossible\n");
    }
}