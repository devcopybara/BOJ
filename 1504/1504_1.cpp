// https://www.acmicpc.net/problem/1504
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n, e;
const int MX = 805;
const int INF= MX * 1'005 * 3;
vector<pii> adj[MX];
int dist[MX];
int point[2];
int dijkstra(int st, int en) {
    fill(dist,dist+1+n,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;

    dist[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if(d != dist[u]) continue;
        for(auto [w,v] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[en];
}

int solve(int way) {
    int ans = 0;
    if(way) {
        ans += dijkstra(1,point[0]);
        ans += dijkstra(point[0],point[1]);
        ans += dijkstra(point[1],n);
    }
    else {
        ans += dijkstra(1,point[1]);
        ans += dijkstra(point[1],point[0]);
        ans += dijkstra(point[0],n);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> e;
    while(e--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    cin >> point[0] >> point[1];

    int ans = min(solve(0), solve(1));
    cout << (ans >= INF ? -1 : ans);
}