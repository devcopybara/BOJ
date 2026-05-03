// https://www.acmicpc.net/problem/20040
#include <bits/stdc++.h>
using namespace std;

const int MX = 500'005;
int p[MX];

int find(int u) {
    if(p[u] < 0) return u;

    return p[u] = find(p[u]);
}

int uni(int u, int v) {
    u = find(u);
    v = find(v);

    if(u == v) return 0;

    if(p[u] > p[v]) swap(u,v);
    if(p[u] == p[v]) p[u]--;

    p[v] = u;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(p,p+MX,-1);

    int n, m; cin >> n >> m;
    
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(ans != 0) continue;
        if(!uni(u,v)) ans = i;
    }
    cout << ans;
}