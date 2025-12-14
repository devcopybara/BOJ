#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n, m, t;
int adj[302][302];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }
    while(m--) {
        int u, v, h;
        cin >> u >> v >> h;
        adj[u][v] = h;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));

    while(t--) {
        int s, e;
        cin >> s >> e;
        if(adj[s][e] == INF) cout << "-1\n";
        else cout << adj[s][e] << '\n';
    }
}