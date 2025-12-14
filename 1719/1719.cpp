#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

int n, m;
int adj[202][202];
int nxt[202][202];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
        nxt[u][v] = v, nxt[v][u] = u;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1;  j <= n; j++) {
                if(adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    
    for(int i = 1; i <= n; i++) {
        for(int j = 1;  j <= n; j++) {
            if(adj[i][j] == 0) cout << "- ";
            else cout << nxt[i][j] << ' ';
        }
        cout << '\n';
    }
}