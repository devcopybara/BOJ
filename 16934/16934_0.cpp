#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000 * 10 + 5;
int nxt[MX][26];
int x[MX]; // chk
int ROOT = 1;
int unused = 2;
int c2i(char c) {
    return c-'a';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s, alias = "";
        cin >> s;

        int cur = ROOT;
        bool isprefix = false;
        for(char c : s) {
            if(!isprefix)
                alias += c;

            int idx = c2i(c);

            if(nxt[cur][idx] == 0) {
                nxt[cur][idx] = unused++;
                isprefix = true;
            }
            
            cur = nxt[cur][idx];
        }

        x[cur]++;
        if(x[cur] > 1)
            alias += to_string(x[cur]);
        cout << alias << '\n';
    }
}