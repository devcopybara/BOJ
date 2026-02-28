#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int,int>> adj[1'005];
int dist[1'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    while(m--) {
        int u, v;
        cin >> u >> v;

        fill(dist+1, dist+1+n, -1);

        queue<int> q;
        q.push(u);
        dist[u] = 0;
        while(!q.empty()) {
            if(dist[v] != -1) break;
            int cur = q.front(); q.pop();
            for(auto nxt : adj[cur]) {
                if(dist[nxt.X] != -1) continue;
                q.push(nxt.X);
                dist[nxt.X] = dist[cur] + nxt.Y;
            }
        }
        cout << dist[v] << '\n';
    }
}