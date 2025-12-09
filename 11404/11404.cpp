#include <bits/stdc++.h>
using namespace std;
#define INF 10'000'000
int n, m;
int adj[102][102];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }

    for(int k = 1; k <= n; k++)
        for(int s = 1; s <= n; s++)
            for(int t = 1; t <= n; t++)
                adj[s][t] = min(adj[s][t], adj[s][k] + adj[k][t]);
    
    for(int s = 1; s <= n; s++) {
        for(int t = 1; t <= n; t++) {
            cout << (adj[s][t] == INF ? 0 : adj[s][t]) << ' ';
        }
        cout << '\n';
    }
}