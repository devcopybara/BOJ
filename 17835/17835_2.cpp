// https://www.acmicpc.net/problem/17835
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using int64 = long long;
#define X first
#define Y second
#define INF 0x3f3f3f3f
const int MX = 100'005;
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<pii> adj[MX];
int d[MX];
int n, m, k;

vector<bool> state(MX,false);

int dijkstra(int st, int* d) {
    fill(d+1, d+1+n, INF);
    d[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        if(state[cur.Y]) return cur.X;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({c,v});
    }

    while(k--) {
        int tmp;
        cin >> tmp;
        state[tmp] = true;
    }

    int max_dist = 0, min_idx = 0;
    for(int i = 1; i <= n; i++) {
        if(state[i]) continue;

        int min_dist = dijkstra(i,d);

        if(max_dist < min_dist) {
            max_dist = min_dist;
            min_idx = i;
        }
    }

    cout << min_idx << '\n' << max_dist;
}