#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
vector<pair<int,int>> adj[100'005];
int dist[100'005];

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
    int u, v, w;
    for(int i = 0; i < n; i++) {
        cin >> u;
        while(1) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back({v,w});
        }
    }

    max_dist = 0, max_node = 1;
    bfs(1);

    max_dist = 0;
    bfs(max_node);

    cout << max_dist;
}