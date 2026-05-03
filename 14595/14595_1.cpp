// https://www.acmicpc.net/problem/14595
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
int p[MX];

int find(int u) {
    if(p[u] < 0) return u;
    return p[u] = find(p[u]);
}

int uni(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return u;

    if(u < v) swap(u,v);
    p[v] = u;
    return u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    fill(p,p+1+n,-1);
    while(m--) {
        int st, en; cin >> st >> en;
        for(int i = st+1; i <= en; i++) {
            i = uni(st,i);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(p[i] < 0) ans++;
    }
    cout << ans;
}