#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;
int v,e;
vector<pii> adj[10'005];
bool chk[10'005];
priority_queue<pii,vector<pii>, greater<pii>> pq;
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    chk[1] = true;
    for(auto nxt : adj[1])
        pq.push(nxt);

    int ans = 0;
    while(cnt < v-1) {
        auto cur = pq.top(); pq.pop();
        if(chk[cur.Y]) continue;
        ans += cur.X;
        chk[cur.Y] = true;
        for(auto nxt : adj[cur.Y])
            pq.push(nxt);
        cnt++;
    }
    cout << ans;
}