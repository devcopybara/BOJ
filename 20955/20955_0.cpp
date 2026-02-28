#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100'005];
int gCnt;
int cCnt;
int p[100'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if(p[i]) continue;
        gCnt++;

        queue<int> q;
        q.push(i);
        
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]) {
                if(nxt == p[cur]) continue;
                if(p[nxt]) { cCnt++; continue; }
                q.push(nxt);
                p[nxt] = cur;
            }
        }
    }

    cout << gCnt-1 + cCnt / 2;
}