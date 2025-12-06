#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
vector<pair<int,int>> adj[105];
int deg[105];
int tot[105];
void dfs(int cur, int cnt) {
    if(deg[cur] == 0) {
        tot[cur] += cnt;
        return;
    }
    
    for(auto nxt : adj[cur]) {
        dfs(nxt.X, nxt.Y * cnt);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y,k;
        cin >> x >> y >> k;
        adj[x].push_back({y,k});
        deg[x]++;
    }
    dfs(n,1);
    for(int i = 1; i < n; i++) {
        if(tot[i])
            cout << i << ' ' << tot[i] << '\n';
    }
}