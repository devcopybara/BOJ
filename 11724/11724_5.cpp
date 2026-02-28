// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
int edge[MX*MX][2];
int deg[MX];
int idx[MX];
int* adj[MX];
int vis[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[i][0] = u, edge[i][1] = v;
        deg[u]++,deg[v]++;
    }

    for(int i = 1; i <= n; i++) {
        adj[i] = new int[deg[i]];
    }

    for(int i = 0; i < m; i++) {
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v, adj[v][idx[v]] = u;
        idx[u]++, idx[v]++;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        cnt++;

        queue<int> q;
        vis[i] = 1;
        q.push(i);

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(int i = 0; i < idx[cur]; i++) {
                auto nxt = adj[cur][i];
                if(vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    cout << cnt;
}