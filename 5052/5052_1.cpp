// https://www.acmicpc.net/problem/5052
#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000 * 10 + 5;
int chk[MX];
int nxt[MX][10];
const int ROOT = 1;
int unused = 2;

int c2i(char c) {
    return c-'0';
}

bool insert(string& s) {
    bool isvalid = false;

    int cur = ROOT;
    for(char c : s) {
        if(chk[cur] == 1) return false;

        if(nxt[cur][c2i(c)] == 0) {
            nxt[cur][c2i(c)] = unused++;
            isvalid = true;
        }
        cur = nxt[cur][c2i(c)];
    }
    if(!isvalid) return false;
    chk[cur] = 1;
    return isvalid;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        unused = 2;
        fill(chk,chk+1+MX,0);
        for(int i = 0; i < MX; i++) fill(nxt[i],nxt[i]+10,0);

        bool isvalid = true;

        while(n--){
            string s; cin >> s;
            if(!insert(s)) isvalid = false;
        }

        if(isvalid) cout << "YES\n";
        else cout << "NO\n";
    }
}