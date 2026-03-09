// https://www.acmicpc.net/problem/1238
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, m, x;
const int MX = 1'005;
const int INF= MX * 100;
vector<pii> adj[MX];
int dist[MX];
int ans[MX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dijkstra(int st) {
    fill(dist+1,dist+n+1,INF);

    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [w, v] : adj[u]) {
            if(dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w,v});
    }

    for(int i = 1; i <= n; i++) {
        ans[i] += dijkstra(i);

        if(i == x) {
            for(int j = 1; j <= n; j++)
                ans[j] += dist[j];
        }
    }

    int max_ans = 0;
    for(int i = 1; i <= n; i++) 
        max_ans = max(max_ans, ans[i]);
    cout << max_ans;
}