// https://www.acmicpc.net/problem/1717
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

    int n, m; cin >> n >> m;
    fill(p+1,p+1+n,-1);
    while(m--) {
        int a,b,c; cin >> c >> a >> b;

        if(c == 1) {
            if(find(a) == find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            uni(a,b);
        }
    }
}