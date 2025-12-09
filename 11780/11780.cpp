#include <bits/stdc++.h>
using namespace std;
#define INF 10'000'000
int n, m;
int adj[102][102];
int nxt[102][102];
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
        if(adj[a][b] > c) {
             adj[a][b] = c;
             nxt[a][b] = b;
        }
    }

    for(int k = 1; k <= n; k++)
        for(int s = 1; s <= n; s++)
            for(int t = 1; t <= n; t++)
                if(adj[s][t] > adj[s][k] + adj[k][t]) {
                    adj[s][t] = adj[s][k] + adj[k][t];
                    nxt[s][t] = nxt[s][k];
                }
    
    for(int s = 1; s <= n; s++) {
        for(int t = 1; t <= n; t++) {
            cout << (adj[s][t] == INF ? 0 : adj[s][t]) << ' ';
        }
        cout << '\n';
    }

    for(int s = 1; s <= n; s++) {
        for(int t = 1; t <= n; t++) {
            if(adj[s][t] == 0 || adj[s][t] == INF)
                cout << "0\n";
            else {
                vector<int> path;
                int cur = s;
                while(cur != t) {
                    path.push_back(cur);
                    cur = nxt[cur][t];
                }   path.push_back(cur);
                cout << path.size() << ' ';
                for(int u : path)
                    cout << u << ' ';
            }
            cout << '\n';
        }
    }
}