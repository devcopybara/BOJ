// https://www.acmicpc.net/problem/11779
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MX = 1'002;
const int INF= MX * 100'000;
vector<pii> adj[MX];
int dist[MX];
int pre[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }
    
    int st, en;
    cin >> st >> en;

    fill(dist+1,dist+1+n,INF);
    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [w, v] : adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
                pre[v] = u;
            }
        }
    }

    cout << dist[en] << "\n";

    vector<int> route;
    int cur = en;
    while(cur != 0) {
        route.push_back({cur});
        cur = pre[cur];
    }
    int sz = route.size();
    cout << sz << "\n";
    for(int i = sz-1; i >= 0; i--) cout << route[i] << " ";
}