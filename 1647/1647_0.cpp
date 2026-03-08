#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;
const int MX = 100'005;
int n, m;
vector<pii> adj[MX];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> chk(MX,false);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    chk[1] = true;
    for(auto nxt : adj[1])
        if(!chk[nxt.Y] && nxt.X) 
            pq.push(nxt);

    int ans = 0;
    int max_cost = 0;
    int cnt = 0;

    while(cnt < n-1) {
        auto cur = pq.top(); pq.pop();
        int cost = cur.X;
        int u = cur.Y;

        if(chk[u]) continue;
        chk[u] = true;
        max_cost = max(max_cost, cost);
        ans += cost;
        cnt++;

        for(auto nxt : adj[u])
            if(!chk[nxt.Y] && nxt.X) 
                pq.push(nxt);
    }

    cout << ans - max_cost;
}