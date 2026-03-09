#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define X first
#define Y second
using pii = pair<int,int>;
const int MX = 1005;
int v, e, st, en;
vector<pii> adj[MX];
int d[MX];
int pre[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    while(e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    cin >> st >> en;

    fill(d+1, d+1+v, INF);
    d[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if(d[cur.Y] != cur.X) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
            pre[nxt.Y] = cur.Y;
        }
    }

    cout << d[en] << '\n';

    vector<int> path;
    int cur = en;
    while(cur != 0) {
        path.push_back(cur);
        cur = pre[cur];
    }
    int sz = path.size(); 
    cout << sz << '\n';
    for(int i = sz - 1; i >= 0; i--)
        cout << path[i] << ' ';
}