// https://www.acmicpc.net/problem/1976
#include <bits/stdc++.h>
using namespace std;

const int MXN = 202;
int p[MXN];

int find(int u) {
    if(p[u] < 0) return u;

    return p[u] = find(p[u]);
}

int uni(int u, int v) {
    u = find(u);
    v = find(v);

    if(v == u) return 0;

    if(p[v] < p[u]) swap(u,v);
    if(p[v] == p[u]) p[u]--;

    p[v] = u;
    return 1;
}

int adj[MXN][MXN];

const int MXM = 1'002;
int travel[MXM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    fill(p,p+1+n,-1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if(adj[i][j]) uni(i,j);
        }
    }

    bool ans = true;
    int u, v; 
    m--; cin >> v;
    while(m--) {
        cin >> u;
        if(find(u) != find(v)) ans = false;
        v = u;
    }
    cout << (ans ? "YES" : "NO");
}