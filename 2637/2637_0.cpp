// https://www.acmicpc.net/problem/2637
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

const int MX = 102;
int n,m;
vector<pii> adj[MX];
int deg[MX];
map<int,int> parts[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        adj[y].push_back({x,k});
        deg[x]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            q.push(i);
            parts[i][i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(auto nxt : adj[cur]) {
            deg[nxt.X]--;
            if(deg[nxt.X] == 0) {
                q.push(nxt.X);
            }
            for(auto part : parts[cur]) {
                parts[nxt.X][part.X] += nxt.Y * part.Y;
            }
        }
    }

    for(auto part : parts[n]) {
        cout << part.X << " "  << part.Y <<"\n";
    }
}