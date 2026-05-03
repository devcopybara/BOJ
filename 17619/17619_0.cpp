// https://www.acmicpc.net/problem/17619
#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

const int MX = 100'002;
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
    
    int n, q; cin >> n >> q;
    fill(p,p+1+n,-1);

    vector<ti3> v(n);
    for(int i = 0; i < n; i++) { 
        int x1, x2, y; cin >> x1 >> x2 >> y;
        v[i] = {x1,x2,i+1};
    }

    sort(v.begin(), v.end());

    int mx = -1;
    int j = 0;
    for(int i = 0; i < n; i++) {
        auto [x1,x2,k] = v[i];
        if(x1 > mx) {
            mx = x2;
        }
        else {
            uni(j, k);
            mx = max(mx, x2);
        }
        j = k;
    }

    while(q--) {
        int u,v; cin >> u >> v;
        cout << (find(u) == find(v)) << '\n';
    }
}