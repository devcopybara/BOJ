// https://www.acmicpc.net/problem/5214
#include <bits/stdc++.h>
using namespace std;
const int MX = 100'005;
int n, k, m;
vector<int> adj[MX];
int dist[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int h = 1; h <= m; h++) {
        vector<int> h2s;
        for(int i = 0; i < k; i++) {
            int s;
            cin >> s;
            h2s.push_back(s);
        }
        for(int i = 0; i < k; i++) {
            int u = h2s[i];
            for(int j = i+1; j < k; j++) {
                int v = h2s[j];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }
    fill(dist,dist+1+n,-1);
    
    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(!q.empty() && dist[n] == -1) {
        auto cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            q.push(nxt);
        }
    }
    cout << dist[n];
}