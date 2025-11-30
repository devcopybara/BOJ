#include <bits/stdc++.h>
using namespace std;
vector<int> adj[505];
int p[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while(1) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        fill(p+1,p+1+n,0);
        for(int i = 1; i <= n; i++) {
            if(p[i]) continue;
            bool istree = true;
            
            queue<int> q;
            q.push(i);
            while(!q.empty()) {
                int cur = q.front(); q.pop();
                for(int nxt : adj[cur]) {
                    if(nxt == p[cur]) continue;
                    if(p[nxt]) {
                        istree = false;
                        continue;
                    }
                    q.push(nxt);
                    p[nxt] = cur;
                }
            }
            
            if(istree) ans++;
        }

        
        cout << "Case " << t++ << ": ";
        if(ans == 0) cout << "No trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << ans << " trees.\n";
    }
}