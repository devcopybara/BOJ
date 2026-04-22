// https://www.acmicpc.net/problem/5670
#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 * 81 + 5;
map<int,int> nxt[MX];
const int ROOT = 1;
int unused = ROOT+1;

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(!nxt[cur][c]) nxt[cur][c]=unused++;
        cur = nxt[cur][c];
    }
    if(!nxt[cur][0]) nxt[cur][0]=unused++;
}

int find(string& s) {
    int cnt = 1;

    int cur = nxt[ROOT][s[0]], len = s.length();
    for(int i = 1; i < len; i++) {
        if(nxt[cur].size() > 1) cnt++;
        cur = nxt[cur][s[i]];
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n) {
        unused = ROOT+1;

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
        
        for(int i = 1; i < unused; i++) nxt[i].clear();
    }
}