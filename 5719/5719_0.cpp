// https://www.acmicpc.net/problem/5719
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, m;
int src, dst;
const int MX = 502;
const int INF= MX * 1e4;
vector<pii> adj[MX];
vector<pii> radj[MX];
int dist[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;
bool vis[MX];
queue<int> q;

bool ban[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> src >> dst;

        for(int i = 0; i < n; i++) {
            adj[i].clear();
            radj[i].clear();
        }

        while(m--) {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({p,v});
            radj[v].push_back({p,u});
        }

        fill(dist,dist+n,INF);
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if(d != dist[u]) continue;
            for(auto [p,v] : adj[u]) {
                if(dist[v] > d + p) {
                    dist[v] = d + p;
                    pq.push({dist[v],v});
                }
            }
        }

        for(int i = 0; i <= n; i++)
            fill(ban[i],ban[i]+n,0);
        fill(vis,vis+n,0);

        vis[dst] = 1;
        q.push(dst);

        while(!q.empty()) {
            auto v = q.front(); q.pop();
            for(auto [p, u] : radj[v]) {
                if(dist[u] + p == dist[v]) {
                    ban[u][v] = 1;
                    if(vis[u]) continue;
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }

        fill(dist,dist+n,INF);
        dist[src] = 0;
        pq.push({0,src});

        while(!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();
            if(d != dist[u]) continue;
            for(auto [p,v] : adj[u]) {
                if(ban[u][v]) continue;
                if(dist[v] > d + p) {
                    dist[v] = d + p;
                    pq.push({dist[v],v});
                }
            }
        }

        if(dist[dst] == INF) cout << -1 << '\n';
        else cout << dist[dst] << '\n';
    }
}