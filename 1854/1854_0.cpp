// https://www.acmicpc.net/problem/1854
#include <bits/stdc++.h>
using namespace std;
using pii = pair<uint64_t,uint64_t>;

const uint64_t MXN = 1'005;
const uint64_t MXK = 102;
const uint64_t INF = MXN * 1'000 * MXK;
vector<pii> adj[MXN];
priority_queue<uint64_t> dist[MXN];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n,m,k;
    cin >> n >> m >> k;
    while(m--) {
        uint64_t a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    dist[1].push(0);
    pq.push({0,1});

    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        for(auto [c,v] : adj[u]) {
            uint64_t nd = d + c;
            if(dist[v].size() < k) {
                dist[v].push(nd);
                pq.push({nd,v});
            }
            else if(dist[v].top() > nd) {
                dist[v].pop(); dist[v].push(nd);
                pq.push({nd,v});
            }
        }
    }

    for(uint64_t i = 1; i <= n; i++) {
        if(dist[i].size() < k) cout << -1 << '\n';
        else cout << dist[i].top() << '\n';
    }
}