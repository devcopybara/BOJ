// https://www.acmicpc.net/problem/1260
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
vector<int> adj[MX];

vector<bool> svis(MX,false);
void dfs(int cur) {
    cout << cur << ' ';
    svis[cur] = 1;
    for(auto nxt : adj[cur]) {
        if(svis[nxt]) continue;
        dfs(nxt);
    }
}

vector<bool> qvis(MX,false);
void bfs(int v) {
    queue<int> q;
    qvis[v] = 1;
    q.push(v);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        cout << cur << ' ';
        for(auto nxt : adj[cur]) {
            if(qvis[nxt]) continue;
            qvis[nxt] = 1;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,v;
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
    bfs(v);
}