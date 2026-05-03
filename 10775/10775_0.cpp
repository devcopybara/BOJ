// https://www.acmicpc.net/problem/10775
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
int p[MX];

int find(int u) {
    if(p[u] < 0) return u;
    return p[u] = find(p[u]);
}

int uni(int u, int v) {
    u = find(u);
    // v = find(v);
    // if(u == v) return 0;
    p[v] = u;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    fill(p,p+1+n,-1);

    int ans = 0;
    bool iscloesd = false;
    while(m--) {
        int g; cin >> g;
        if(iscloesd) continue;

        int x = find(g);
        if(x == 0) iscloesd = true;
        else {
            uni(x-1,x);
            ans++;
        }
    }
    cout << ans;
}