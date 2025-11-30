// https://www.acmicpc.net/problem/2533

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[1'000'005];
int p[1'000'005];
int tot;

int dfs(int cur) {
    int sz = adj[cur].size(), cnt = 0;

    for(int nxt : adj[cur]) {
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        cnt += dfs(nxt);
    }

    if(cur == 1) {
        if(sz == cnt) return 0;
    }
    else {
        if(sz-1 == cnt) return 0;
    }

    tot++;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << tot;
}