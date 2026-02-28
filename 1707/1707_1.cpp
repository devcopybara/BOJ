// https://www.acmicpc.net/problem/1707
#include <bits/stdc++.h>
using namespace std;

const int MX = 20'005;
vector<int> adj[MX];
int color[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        fill(color,color+1+n,-1);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool ans = true;
        for(int i = 1; i <= n; i++) {
            if(!ans) break;
            if(color[i] != -1) continue;
            queue<int> q;
            color[i] = 0;
            q.push(i);
            while(!q.empty() && ans) {
                auto cur = q.front(); q.pop();
                for(auto nxt : adj[cur]) {
                    if(color[nxt] == !color[cur]) continue;
                    if(color[nxt] == color[cur]) {ans = false; break;}
                    color[nxt] = !color[cur];
                    q.push(nxt);
                }
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}