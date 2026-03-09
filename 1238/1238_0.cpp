// https://www.acmicpc.net/problem/1238
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
using pii = pair<int,int>;
#define X first
#define Y second
int n, m, x;
vector<pii> adj[1005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist_to_x[1005];
int dist_from_x[1005];
int d[1005];

void dijkstra(int st, int* d) {
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
    cin >> n >> m >> x;
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    for(int i = 1; i <= n; i++) {
        dijkstra(i,d);
        dist_to_x[i] = d[x];
    }
    dijkstra(x,dist_from_x);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dist_to_x[i]+dist_from_x[i]);
    cout << ans;
}