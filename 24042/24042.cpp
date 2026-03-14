// https://www.acmicpc.net/problem/24042
#include <bits/stdc++.h>
using namespace std;
using pii = pair<uint64_t,uint64_t>;
uint64_t n, m;
const uint64_t MX_N = 100'005;
const uint64_t MX_M = 700'005;
const uint64_t INF= MX_N * MX_M * MX_M;
vector<pii> adj[MX_N];
uint64_t dist[MX_N];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(uint64_t i = 0; i < m; i++) {
        uint64_t a, b;
        cin >> a >> b;
        adj[a].push_back({i,b});
        adj[b].push_back({i,a});
    }

    fill(dist+1,dist+1+n,INF);
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [w,v] : adj[u]) {
            uint64_t dist_v = d + (w - d%m +m)%m + 1;
            if(dist[v] <= dist_v) continue;
            dist[v] = dist_v;
            pq.push({dist_v,v});
        }
    }

    cout << dist[n];
}