// https://www.acmicpc.net/problem/1647
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MX = 100'005;
int n, m;
vector<pii> adj[MX];
bool chk[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    chk[1] = 1;
    for(auto [w,v] : adj[1]) {
        pq.push({w,v});
    }

    int ans = 0;
    int maxw= 0;

    while(cnt < n-1) {
        auto [w,v] = pq.top(); pq.pop();
        if(chk[v]) continue;
        chk[v] = 1;
        cnt++;

        ans += w;
        maxw = max(maxw, w);

        for(auto [nw,nv] : adj[v]) {
            if(chk[nv]) continue;
            pq.push({nw,nv});
        }
    }

    cout << ans - maxw;
}