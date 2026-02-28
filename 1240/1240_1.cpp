// https://www.acmicpc.net/problem/1240
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
vector<pair<int,int>> adj[MX];
int p[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i = 0; i < m; i++) {
        fill(p,p+1+n,0);

        int st, en;
        cin >> st >> en;

        queue<pair<int,int>> q;
        q.push({st,0});
        while(!q.empty()) {
            auto [curV, curW] = q.front(); q.pop();
            if(curV == en) {
                cout << curW << '\n';
                break;
            }
            for(auto [nxtV, nxtW] : adj[curV]) {
                if(nxtV == p[curV]) continue;
                p[nxtV] = curV;
                q.push({nxtV, curW+nxtW});
            }
        }
    }
}