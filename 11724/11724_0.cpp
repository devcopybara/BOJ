// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
vector<int> adj[MX];
vector<bool> vis(MX,false);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
            for(auto nxt : adj[cur]) {
                if(vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    cout << cnt;
}