// https://www.acmicpc.net/problem/2533
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 1'000'005;
vector<int> adj[MX];
int p[MX];
vector<int> lvl[MX];
int chk[MX];
int deg[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    q.push(1);
    p[1] = -1;

    int cnt = 0;
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            int cur = q.front(); q.pop();
            lvl[cnt].push_back(cur);
            for(int nxt : adj[cur]) {
                if(nxt == p[cur]) continue;
                q.push(nxt);
                p[nxt] = cur;
            }
        }
        cnt++;
    }

    for(int i = cnt-1; i > 0; i--) {
        for(int u : lvl[i]) {
            if(chk[u]) continue;
            chk[p[u]] = 1;
        }
    }

    int tot = 0;
    for(int i = 1; i <= n; i++) tot += chk[i];
    cout << tot;
}