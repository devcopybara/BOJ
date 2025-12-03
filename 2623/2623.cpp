#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1'005];
int ord[1'005];
int deg[1'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
            cin >> ord[j];
        for(int j = 0; j < k-1; j++) {
            int u = ord[j], v = ord[j+1];
            adj[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0)
            q.push(i);
    }
    
    vector<int> result;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0)
                q.push(nxt);
        }
    }

    if(result.size() != n)
        cout << 0;
    else {
        for(int x : result)
            cout << x << '\n';
    }
}