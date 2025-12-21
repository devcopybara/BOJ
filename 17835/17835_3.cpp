// https://www.acmicpc.net/problem/17835
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using pii = pair<int64,int64>;
#define X first
#define Y second
#define INF 0x7f7f7f7f7f7f
const int64 MX = 100'005;
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<pii> adj[MX];
int64 d[MX];
int64 n, m, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int64 i = 0; i < m; i++) {
        int64 u, v, c;
        cin >> u >> v >> c;
        adj[v].push_back({c,u});
    }

    fill(d+1, d+1+n, INF);
    
    while(k--) {
        int64 st;
        cin >> st;
        d[st] = 0;
        pq.push({0,st});
    }
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    int64 ans = max_element(d + 1, d + n + 1) - d;
    cout << ans << '\n' << d[ans];
}