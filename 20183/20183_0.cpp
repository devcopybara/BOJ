#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
using int64 = long long;
using pii = pair<int64,int64>;
const int MX = 100'005;

vector<pii> adj[MX];
int64 dist[MX];

int n, m, st, en; int64 c;

priority_queue<pii,vector<pii>,greater<pii>> pq;
bool solve(int64 lim) {

    fill(dist+1,dist+1+n,INF);

    dist[st] = 0;
    pq.push({0, st});
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

    if(dist[en] > c) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> st >> en >> c;

    int64 lo = 1, hi = 0;
    while(m--) {
        int64 u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        hi = max(hi, w);
    }

    while(lo < hi) {
        int64 mid = (lo + hi) / 2;
        if(solve(mid)) hi = mid;
        else lo = mid + 1;
    }

    if(solve(lo)) cout << lo;
    else cout << -1;
}