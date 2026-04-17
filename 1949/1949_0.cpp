// https://www.acmicpc.net/problem/1949
#include <bits/stdc++.h>
using namespace std;

const int MX = 10'005;
int a[MX];
vector<int> adj[MX];

int d[MX][2];
int p[MX];

void dfs(int u) {
    d[u][0] = 0;
    d[u][1] = a[u];

    for(int v : adj[u]) {
        if(v == p[u]) continue;
        p[v] = u;

        dfs(v);

        d[u][0] += max(d[v][0],d[v][1]);
        d[u][1] += d[v][0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << max(d[1][0],d[1][1]);
}