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

bool solve(uint64_t lim) {
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    fill(dist+1,dist+1+n,INF);

    dist[a] = 0;
    pq.push({0, a});
    while(!pq.empty()) {
        auto [cCost, cur] = pq.top(); pq.pop();
        if(dist[cur] != cCost) continue;
        for(auto [nCost, nxt] : adj[cur]) {
            if(nCost > lim) continue; // 최대 cost 제한
            if(dist[nxt] <= nCost + cCost) continue;
            dist[nxt] = nCost + cCost;
            pq.push({dist[nxt], nxt});
        }
    }

    if(dist[b] > c) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    uint64_t st = 1e14, en = 0;

    cin >> n >> m >> a >> b >> c;
    while(m--) {
        uint64_t u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});

        st = min(st,w);
        en = max(en,w);
    }

    while(st < en) {
        uint64_t mid = (st+en) / 2;
        if(solve(mid)) {
            en = mid;
        }
        else {
            st = mid+1;
        }
    }

    if(solve(st)) cout << st;
    else cout << -1;
}