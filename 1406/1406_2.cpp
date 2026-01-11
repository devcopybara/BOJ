#include <iostream>
#include <string.h>
using namespace std;

const int MX = 100'000+500'000+5;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

int insert(int addr, char val) {
    dat[unused] = val;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];

    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;

    return unused++;
}

int erase(int addr) {
    if(nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
    nxt[pre[addr]] = nxt[addr];
    return pre[addr];
}

void print() {
    int cur = nxt[0];
    while(cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

string s;
int m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cin >> m;

    int cur = 0;

    int sz = s.size();
    memset(pre,-1,4*(sz+m));
    memset(nxt,-1,4*(sz+m));

    for(char ch : s) {
        cur = insert(cur, ch);
    }
    
    while(m--) {
        char cmd;
        cin >> cmd;
        switch(cmd) {
            case 'L':
                if(pre[cur] != -1) {
                    cur = pre[cur];
                }
                break;
            case 'D':
                if(nxt[cur] != -1) {
                    cur = nxt[cur];
                }
                break;
            case 'B':
                if(cur != 0) {
                    cur = erase(cur);
                }
                break;
            case 'P':
                char ch;
                cin >> ch;
                cur = insert(cur, ch);
                break;
        }
    }

    print();
}