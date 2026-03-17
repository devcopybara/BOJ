// https://www.acmicpc.net/problem/5719
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n, m;
int src, dst;
const int MX = 502;
vector<pii> adj[MX];
int dist[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> src >> dst;

    while(m--) {
        int u, v, p;
        cin >> u >> v >> p;
        adj[u].push_back({p,v});
    }

    
}