// https://www.acmicpc.net/problem/20183
#include <bits/stdc++.h>
using namespace std;
using pii = pair<uint64_t,uint64_t>;
using t3i = tuple<uint64_t,uint64_t,uint64_t>;
uint64_t n, m, a, b, c;
const uint64_t MX = 100'005;
const uint64_t INF= 1e15;
vector<pii> adj[MX];
uint64_t dist[MX];
uint64_t tot[MX];
priority_queue<t3i,vector<t3i>,greater<t3i>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b >> c;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    fill(dist+1,dist+1+n,INF);

    dist[a] = 0;
    tot[a] = 0;
    pq.push({0,0,a});
    while(!pq.empty()) {
        auto [d,t,u] = pq.top(); pq.pop();
        if(dist[u] <= d && tot[u] <= t) continue;
        for(auto [w,v] : adj[u]) {
        }
    }
}