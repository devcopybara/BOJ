// https://www.acmicpc.net/problem/1005
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 1'005;
vector<int> adj[MX];
int deg[MX];
int d[MX];
int s[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        for(int i = 1; i <= n; i++) adj[i].clear();
        fill(deg+1,deg+1+n,0);
        fill(s+1,s+1+n,0);

        for(int i = 1; i <= n; i++) cin >> d[i];
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            deg[y]++;
        }
        int w; cin >> w;

        queue<pii> q;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 0) {
                q.push({i, d[i]});
                s[i] = d[i];
            }
        }

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur.X]) {
                s[nxt] = max(s[nxt], d[nxt] + cur.Y);
                deg[nxt]--;
                if(deg[nxt] == 0) {
                    q.push({nxt, s[nxt]});
                }
            }
        }

        cout << s[w] << '\n';
    }
}