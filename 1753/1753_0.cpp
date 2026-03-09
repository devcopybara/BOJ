#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
#define X first
#define Y second
int v, e, k;
vector<pair<int,int>> adj[20'005];
int d[20'005];
bool fix[20'005];
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
    while(1) {
        int idx = -1;
        for(int i = 1; i <= v; i++) {
            if(fix[i]) continue;
            if(idx == -1) idx = i;
            if(d[idx] > d[i]) idx = i;
        }
        if(idx == -1 || d[idx] == INF) break;
        fix[idx] = true;
        for(auto nxt : adj[idx]) {
            d[nxt.Y] = min(d[nxt.Y], d[idx]+nxt.X);
        }
    }

    for(int i = 1;  i <= v; i++) {
        if(d[i] == INF) cout <<  "INF\n";
        else cout << d[i] << '\n';
    }
}