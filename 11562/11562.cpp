#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f'3f'3f'3f
int n, m, k;
int adj[252][252];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u][v] = 0;
        adj[v][u] = !b;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

    cin >> k;
    for(int i = 0; i < k; i++) {
        int s, e;
        cin >> s >> e;
        cout << adj[s][e] << "\n";
    }
}