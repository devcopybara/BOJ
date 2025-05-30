#include <stdio.h>
#include <string.h>

char s[100005];

const int MX = 600005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void traversal() {
    int cur = nxt[0];

    while(cur != -1) {
        printf("%c", dat[cur]);
        cur = nxt[cur];
    }
}

int insert(int addr, char val) {
    dat[unused] = val;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;

    return unused++;
}

int erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];

    return pre[addr];
}


int main(void) {
    memset(pre, -1, sizeof(int) * MX);
    memset(nxt, -1, sizeof(int) * MX);

    int cur = 0;

    scanf("%s", s);
    for(int i = 0; s[i]; i++) cur = insert(cur, s[i]);

    int n;
    scanf("%d", &n);
    getchar();

    while(n--) {
        char cmd;
        scanf("%c", &cmd);
        getchar();
        
        switch(cmd) {
            case 'L':
                if(pre[cur] != -1) cur = pre[cur];
                break;
            case 'D':
                if(nxt[cur] != -1) cur = nxt[cur];
                break;
            case 'B':
                if(cur != 0) cur = erase(cur);
                break;
            case 'P':
            default:
                scanf("%c", &cmd);
                getchar();
                cur = insert(cur, cmd);
                break;
        }
    }

    traversal();
}