#include <bits/stdc++.h>
using namespace std;
int n, m;
int adj[12][12];
int ans = 0x7fffffff;
bool vis[12];
void dfs(int k, int pre, int dist) {
    if(k == n - 1) {
        ans = min(ans, dist);
        return;
    }

    for(int nxt = 0; nxt < n; nxt++) {
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        dfs(k+1,nxt,dist+adj[pre][nxt]);
        vis[nxt] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

    vis[m] = 1;
    dfs(0,m,0);
    cout << ans;
}