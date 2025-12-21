#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define X first
#define Y second
using pii = pair<int,int>;
int v, e, k;
vector<pii> adj[20'005];
int d[20'005];
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

    fill(d+1, d+1+v, INF);
    d[k] = 0;
    pq.push({0,k});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }

    for(int i = 1;  i <= v; i++) {
        if(d[i] == INF) cout <<  "INF\n";
        else cout << d[i] << '\n';
    }
}