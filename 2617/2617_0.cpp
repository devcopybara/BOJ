// https://www.acmicpc.net/problem/2617
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> heavy_adj[100];
vector<int> light_adj[100];

int bfs(int v, vector<int> adj[100]) {
    int cnt = 0;

    queue<int> q;
    vector<bool> vis(n+1,false);

    q.push(v);
    vis[v] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cnt++;
        for(int nxt : adj[cur]) {
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }

    return cnt - 1;
}

int solve() {
    int ans = 0;
    int mid = (n+1) / 2;
    for(int i = 1; i <= n; i++) {
        int heavy_cnt = bfs(i, heavy_adj);
        int light_cnt = bfs(i, light_adj);

        if(light_cnt >= mid || heavy_cnt >= mid)
            ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        light_adj[u].push_back(v);
        heavy_adj[v].push_back(u);
    }

    cout << solve();
}