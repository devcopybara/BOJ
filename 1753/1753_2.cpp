// https://www.acmicpc.net/problem/1753
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MX = 20'005;
const int INF = 10 * MX;

int v, e, k;
vector<pii> adj[MX];
int dist[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> k;
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    fill(dist+1, dist+1+v, INF);
    dist[k] = 0;
    pq.push({0,k});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if(d != dist[u]) continue;
        for(auto [w, v] : adj[v]) {
            if(dist[v] <= d + w) continue;
            dist[v] = d + w;
            pq.push({dist[v], v});
        }
    }

    for(int i = 1;  i <= v; i++) {
        if(dist[i] == INF) cout <<  "INF\n";
        else cout << dist[i] << '\n';
    }
}