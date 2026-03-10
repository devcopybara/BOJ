#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using int64 = long long;
#define X first
#define Y second
#define INF 0x3f3f3f3f
const int MX = 805;
int n, m;
vector<pii> adj[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int v[3];
int64 d[3][MX];

void dijkstra(int st, int64* d) {
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    cin >> v[1] >> v[2];
    v[0] = 1;

    for(int i = 0; i < 3; i++)
        dijkstra(v[i], d[i]);

    int64 ans = INF;
    ans = min(ans, d[0][v[1]]+d[1][v[2]]+d[2][n]);
    ans = min(ans, d[0][v[2]]+d[2][v[1]]+d[1][n]);
    cout << (ans == INF ? -1 : ans);
}