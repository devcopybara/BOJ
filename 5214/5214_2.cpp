// https://www.acmicpc.net/problem/5214
#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<int> adj[101'005];
int dist[101'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int u = n+1; u <= n+m; u++) {
        for(int i = 0; i < k; i++) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    fill(dist,dist+1+n+m,-1);

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        if(dist[n] != -1) {
            cout << dist[n] / 2 + 1;
            return 0;
        }
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    cout << -1;
}