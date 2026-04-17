// https://www.acmicpc.net/problem/1005
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 1'005;
vector<int> adj[MX];
int deg[MX];
int d[MX];
int s[MX];

void dfs(int cur) {
    if(s[cur] != -1) return;

    if(deg[cur] == 0) {
        s[cur] = d[cur];
        return;
    }

    s[cur] = 0;
    for(int pre : adj[cur]) {
        dfs(pre);
        s[cur] = max(s[cur], d[cur] + s[pre]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) adj[i].clear();
        fill(deg+1,deg+1+n,0);
        fill(s+1,s+1+n,-1);

        for(int i = 1; i <= n; i++) cin >> d[i];
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            adj[y].push_back(x);
            deg[y]++;
        }
        int w; cin >> w;

        dfs(w);

        cout << s[w] << '\n';
    }
}