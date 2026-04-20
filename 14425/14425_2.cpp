// https://www.acmicpc.net/problem/14425
#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5; // 최대 등장 가능한 글자의 수
bool chk[MX];
unordered_map<char,int> nxt[MX];

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(nxt[cur][c] == 0)
            nxt[cur][c] = unused++;
        cur = nxt[cur][c];
    }
    chk[cur] = true;
}

bool find(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(nxt[cur][c] == 0)
            return false;
        cur = nxt[cur][c];
    }
    return chk[cur];
}

void erase(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(nxt[cur][c] == 0)
            return;
        cur = nxt[cur][c];
    }
    chk[cur] = false;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    while(n--) {
        string s; cin >> s;
        insert(s);
    }

    int ans = 0;
    while(m--) {
        string s; cin >> s;
        ans += find(s);
    }
    cout << ans;
}