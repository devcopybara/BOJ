// https://www.acmicpc.net/problem/11725
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<int> adj[MX];
int p[MX];

void dfs(int cur) {
    for(auto nxt : adj[cur]) {
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    for(int u = 2; u <= n; u++) {
        cout << p[u] << '\n';
    }
}