#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f'3f'3f'3f
int v, e;
int adj[402][402];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 1; i <= v; i++)
        fill(adj[i]+1, adj[i]+v+1, INF);
    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    for(int k = 1; k <= v; k++) 
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
    
    int ans = INF;
    for(int i = 1; i <= v; i++)
        ans = min(ans, adj[i][i]);
    cout << (ans == INF ? -1 : ans);
}