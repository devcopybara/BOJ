// https://www.acmicpc.net/problem/5670
#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 * 81 + 5;
int nxt[MX][27];
int cnt[MX];
const int ROOT = 1;
int unused = ROOT+1;

int c2i(char c) {
    return c-'a'+1;
}

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(!nxt[cur][c2i(c)]) {nxt[cur][c2i(c)]=unused++; cnt[cur]++;}
        cur = nxt[cur][c2i(c)];
    }
    if(!nxt[cur][0]) {nxt[cur][0]=unused++; cnt[cur]++;}
}

int find(string& s) {
    int ret = 1;

    int cur = nxt[ROOT][c2i(s[0])], len = s.length();
    for(int i = 1; i < len; i++) {
        if(cnt[cur] > 1) ret++;
        cur = nxt[cur][c2i(s[i])];
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n) {
        unused = ROOT+1;
        for(int i = 0; i < MX; i++) fill(nxt[i],nxt[i]+27,0);
        fill(cnt,cnt+MX,0);

        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            insert(v[i]);
        }

        double ans = 0;
        for(string s : v) {
            ans += find(s);
        }

        cout << fixed  << setprecision(2) << ans / n << '\n';
    }
}