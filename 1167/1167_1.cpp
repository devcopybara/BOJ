// https://www.acmicpc.net/problem/1167
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

int n;
const int MX = 100'005;
vector<pii> adj[MX];
bool vis[MX];
pii bfs(int st) {
    fill(vis,vis+n+1,0);
    int max_x = st, max_y = 0;

    queue<pii> q;
    q.push({st,0});
    vis[st] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(max_y < cur.Y) {
            max_y = cur.Y;
            max_x = cur.X;
        }

        for(auto nxt : adj[cur.X]) {
            if(vis[nxt.X]) continue;
            q.push({nxt.X, cur.Y+nxt.Y});
            vis[nxt.X] = 1;
        }
    }

    return {max_x,max_y};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        while(1) {
            int v, w;
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back({v,w});
        }
    }

    auto st = bfs(1);
    auto en = bfs(st.X);
    cout << en.Y;
}