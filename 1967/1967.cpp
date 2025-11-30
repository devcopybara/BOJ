#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
vector<pair<int,int>> adj[10'005];
int dist[10'005];

int max_dist, max_node;
void bfs(int root) {
    fill(dist,dist+1+n,-1);
    queue<int> q;
    q.push(root);
    dist[root] = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(max_dist < dist[cur]) {
            max_dist = dist[cur];
            max_node = cur;
        }
        for(auto nxt : adj[cur]) {
            if(dist[nxt.X] != -1) continue;
            q.push(nxt.X);
            dist[nxt.X] = dist[cur] + nxt.Y;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    max_dist = 0, max_node = 1;
    bfs(1);

    max_dist = 0;
    bfs(max_node);

    cout << max_dist;
}