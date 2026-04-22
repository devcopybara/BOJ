// https://www.acmicpc.net/problem/16934
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000 * 10 + 5;
int chk[MX];
int nxt[MX][26];
const int ROOT = 1;
int unused = 2;

int c2i(char c) {
    return c-'a';
}

string insert(string& s) {
    string nick;
    bool isprefix = false;
    int cur = ROOT;
    for(char c : s) {
        if(!isprefix) nick += c;
        if(nxt[cur][c2i(c)] == 0) {
            nxt[cur][c2i(c)] = unused++;
            isprefix = true;
        }
        cur = nxt[cur][c2i(c)];
    }
    chk[cur]++;
    if(chk[cur] == 1) isprefix = true;
    if(!isprefix) nick += to_string(chk[cur]);
    return nick;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        cout << insert(s) << '\n';
    }
}