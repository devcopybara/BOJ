#include <bits/stdc++.h>
using namespace std;

const int MX = 600005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

void traversal() {
    int cur = nxt[0];

    while(cur != -1) {
        cout << dat[cur];
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);

    string s;
    cin >> s;

    int cur = 0;
    for(char ch : s) cur = insert(cur, ch);

    int n;
    cin >> n;

    while(n--) {
        char cmd;
        cin >> cmd;
        
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
                cin >> cmd;
                cur = insert(cur, cmd);
                break;
        }
    }

    traversal();
}