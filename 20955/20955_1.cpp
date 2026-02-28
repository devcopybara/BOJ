// https://www.acmicpc.net/problem/20955
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<int> adj[MX];
int p[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans1 = 0, ans2 = 0;

    for(int i = 1; i <= n; i++) {
        if(p[i]) continue;
        ans1++;

        queue<int> q;
        q.push(i);
        p[i] = -1;

        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int nxt : adj[cur]) {
                if(nxt == p[cur]) continue;

                if(p[nxt]) { ans2++; continue; }

                q.push(nxt);
                p[nxt] = cur;
            }
        }
    }

    cout << ans1-1 + ans2/2;
}