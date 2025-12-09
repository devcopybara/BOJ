#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n, m, r;
int t[102];
int adj[102][102];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }

    for(int i = 1; i <= n; i++)
        cin >> t[i];

    while(r--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    int max_cnt = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(adj[i][j] <= m) {
                cnt += t[j];
            }
        }
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt;
}