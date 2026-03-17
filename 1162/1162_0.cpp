// https://www.acmicpc.net/problem/1162
#include <bits/stdc++.h>
using namespace std;
using pii = pair<uint64_t,uint64_t>;
using ti3 = tuple<uint64_t,uint64_t,uint64_t>;
const uint64_t MX_N = 10'005;
const uint64_t MX_K = 21;
const uint64_t INF = MX_N * 1'000'000;
vector<pii> adj[MX_N];
uint64_t dist[MX_K][MX_N];
priority_queue<ti3,vector<ti3>,greater<ti3>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n,m,k;
    cin >> n >> m >> k;

    while(m--) {
        uint64_t u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }

    for(uint64_t i = 0; i <= k; i++) 
        fill(dist[i]+1,dist[i]+1+n,INF);

    dist[0][1] = 0;
    pq.push({0,0,1});
    while(!pq.empty()) {
        auto [curD,curK,curV] = pq.top(); pq.pop();
        if(curD != dist[curK][curV]) continue;

        for(auto [nxtW, nxtV] : adj[curV]) {
            uint64_t nxtK = curK + 1;
            
            if(dist[curK][nxtV] > curD + nxtW) {
                dist[curK][nxtV] = curD + nxtW;
                pq.push({dist[curK][nxtV],curK,nxtV});
            }
            
            if(curK == k) continue;
            if(dist[nxtK][nxtV] > curD) {
                dist[nxtK][nxtV] = curD;
                pq.push({dist[nxtK][nxtV],nxtK,nxtV});
            }
        }
    }

    uint64_t ans = INF;
    for(uint64_t i = 0; i <= k; i++)
        ans = min(ans,dist[i][n]);
    cout << ans;
}