#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;
const int MX = 100'005;
int n, m, k;
vector<pii> adj[MX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> chk(MX,false);

int ans;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    vector<int> power_station;
    while(k--) {
        int u;
        cin >> u;
        chk[u] = true;
        cnt++;
        power_station.push_back(u);
    }

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    for(int u : power_station) {
        for(auto nxt : adj[u])
            if(!chk[nxt.Y]) 
                pq.push(nxt);
    }

    while(cnt < n) {
        auto cur = pq.top(); pq.pop();
        int cost = cur.X;
        int u = cur.Y;

        if(chk[u]) continue;
        chk[u] = true;
        cnt++;
        ans += cost;

        for(auto nxt : adj[u])
            if(!chk[nxt.Y]) 
                pq.push(nxt);
    }

    cout << ans;
}