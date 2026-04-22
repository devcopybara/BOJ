// https://www.acmicpc.net/problem/5670
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 1e5 * 80 + 5;
int cnt[MX];
map<int, map<char,int>> nxt;
const int ROOT = 1;
int unused = 2;

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {
        if(!nxt[cur][c]) nxt[cur][c]=unused++;
        cur = nxt[cur][c];
        cnt[cur]++;
    }
    cur = nxt[cur][0];
}

int dfs(bool isauto, int cur) {
    int ret = 0;
    
    if(!isauto) {
        ret += cnt[cur];
    }

    for(auto a : nxt[cur]) {
        ret += dfs(nxt[cur].size() == 1, a.Y);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n) {
        unused = ROOT+1;

        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            insert(s);
        }

        double ans = 0;
        for(auto a : nxt[ROOT]) {
            ans += dfs(false, a.Y);
        }
        cout << fixed  << setprecision(2) << ans / n << '\n';

        for(int i = 1; i < unused; i++) nxt[i].clear();
        fill(cnt+1,cnt+unused,0);
    }
}