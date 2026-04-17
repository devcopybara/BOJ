// https://www.acmicpc.net/problem/7511
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
int p[MX];

int find(int x) {
    if(p[x] < 0) return x;
    
    return p[x] = find(p[x]);
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

    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        int n; cin >> n;
        if(n == 0) break;
        cout << "Scenario " << i << ":\n"; 
        fill(p,p+n,-1);

        int k; cin >> k;
        while(k--) {
            int a,b; cin >> a >> b;
            uni(a,b);
        }

        int m; cin >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            cout << (find(u) == find(v)) << '\n';
        }

        cout << '\n';
    }
}