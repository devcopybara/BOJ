// https://www.acmicpc.net/problem/17835
#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;
using pii = pair<uint64,uint64>;
uint64 n, m, k;
const uint64 MX = 100'005ULL;
const uint64 INF= MX * 100'005ULL;
vector<pii> adj[MX];
uint64 dist[MX];
uint64 min_dist[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;

void dijkstra(uint64 st) {
    fill(dist+1,dist+1+n,INF);

    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [w,v] : adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    while(m--) {
        uint64 u,v,c;
        cin >> u >> v >> c;
        adj[v].push_back({c,u});
    }

    fill(min_dist+1,min_dist+1+n,INF);
    while(k--) {
        int st;
        cin >> st;
        dijkstra(st);

        for(uint64 i = 1; i <= n; i++)
            min_dist[i] = min(min_dist[i], dist[i]);
    }
    uint64 max_i = 0, max_d = 0;
    for(uint64 i = 1; i <= n; i++) {
        if(min_dist[i] != INF) {
            if(max_d < min_dist[i]) {
                max_d = min_dist[i];
                max_i = i;
            }
        }
    }
    cout << max_i << "\n" << max_d;
}