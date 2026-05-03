// https://www.acmicpc.net/problem/1197
#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

const int MX = 1e5 + 5;
ti3 edge[MX];
int p[MX];

int find(int u) {
    if(p[u] < 0) return u;
    return p[u] = find(p[u]);
}

int uni(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return 0;

    if(p[u] > p[v]) swap(u,v);
    if(p[u] == p[v]) p[u]--;

    p[v] = u;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v, e; cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge,edge+e);

    int ans = 0;

    fill(p,p+1+v,-1);
    int cnt = 0;
    for(int i = 0; i < e; i++) {
        auto [c,a,b] = edge[i];

        if(find(a) == find(b)) continue;
        
        uni(a,b);
        ans += c;
        cnt++;
        if(cnt == v-1) break;
    }

    cout << ans;
}