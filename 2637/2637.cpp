#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
vector<pair<int,int>> adj[105];
int deg[105];
int tot[105];
void bfs(int root) {
    queue<pair<int,int>> q;
    q.push({root,1});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();

        if(deg[cur.X] == 0) tot[cur.X] += cur.Y;
        else {
            for(auto nxt : adj[cur.X]) {
                q.push({nxt.X, nxt.Y*cur.Y});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y,k;
        cin >> x >> y >> k;
        adj[x].push_back({y,k});
        deg[x]++;
    }
    bfs(n);
    for(int i = 1; i < n; i++) {
        if(tot[i])
            cout << i << ' ' << tot[i] << '\n';
    }
}