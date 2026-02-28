#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[32'005];
int deg[32'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) q.push(i);
    
    vector<int> result;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }

    for(auto x : result) cout << x << ' ';
}