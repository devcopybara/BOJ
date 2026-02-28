#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> adj[20'005];
int dist[20'005];

bool solve() {
    queue<int> q;
    for(int i = 1; i <= v; i++) {
        if(dist[i] != -1) continue;

        q.push(i);
        dist[i] = 0;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]) {
                if(dist[nxt] != -1) {
                    if((dist[cur] & 1) == (dist[nxt] & 1)) return false;
                    continue;
                }
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    while(k--) {
        cin >> v >> e;
        for(int i = 1; i <= v; i++)
            adj[i].clear();
        fill(dist+1, dist+v+1, -1);

        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}