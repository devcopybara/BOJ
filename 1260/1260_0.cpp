#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1'005];
vector<bool> bvis(1'005,false);
vector<bool> dvis(1'005,false);
int n, m, v;

void dfs(int cur) {
    dvis[cur] = true;
    cout << cur << ' ';
    for(auto nxt : adj[cur]) {
        if(dvis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);
    cout << '\n';

    queue<int> q;
    q.push(v);
    bvis[v] = true;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]) {
            if(bvis[nxt]) continue;
            q.push(nxt);
            bvis[nxt] = true; 
        }
    }
}