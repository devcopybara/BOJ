// https://www.acmicpc.net/problem/2252
#include <bits/stdc++.h>
using namespace std;

const int MX = 32'005;
vector<int> adj[MX];
int deg[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        deg[a]++;
        adj[b].push_back(a);
    }

    queue<int> q;
    for(int u = 1; u <= n; u++) {
        if(deg[u] == 0) q.push(u);
    }

    vector<int> res;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        res.push_back(cur);
        for(auto nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    for(int i = res.size()-1; i >= 0; i--) {
        cout << res[i] << ' ';
    }
}