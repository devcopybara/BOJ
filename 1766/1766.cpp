#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[32'005];
int deg[32'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }

    for(int x : result) {
        cout << x << ' ';
    }
}