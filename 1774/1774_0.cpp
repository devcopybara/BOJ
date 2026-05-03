// https://www.acmicpc.net/problem/1774
#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int64_t,int64_t,int64_t>;
using pii = pair<int64_t,int64_t>;
#define X first
#define Y second

const int64_t MXN = 1'005;
const int64_t MXE = MXN * MXN;
ti3 edge[MXE];

pii pos[MXN];
int64_t p[MXN];

int64_t find(int64_t u) {
    if(p[u] < 0) return u;
    return p[u] = find(p[u]);
}

int64_t uni(int64_t u, int64_t v) {
    u = find(u), v = find(v);

    if(u == v) return 0;

    if(p[u] > p[v]) swap(u,v);
    if(p[u] == p[v]) p[u]--;
    p[v] = u;
    return 1;
}

int64_t dist(int64_t u, int64_t v) {
    return (pos[u].X-pos[v].X)*(pos[u].X-pos[v].X) + (pos[u].Y-pos[v].Y)*(pos[u].Y-pos[v].Y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, m; cin >> n >> m;
    fill(p, p+1+n, -1);
    for(int64_t i = 1; i <= n; i++) {
        int64_t x,y; cin >> x >> y;
        pos[i] = {x,y};
    }

    for(int64_t i = 0; i < m; i++) {
        int64_t u,v; cin >> u >> v;
        uni(u,v);
    }

    int64_t eCnt = 0;
    for(int64_t i = 1; i <= n; i++) {
        for(int64_t j = i+1; j <= n; j++) {
            edge[eCnt++] = {dist(i,j),i,j};
        }
    }
    sort(edge, edge+eCnt);

    double ans = 0.;

    int64_t cnt = m;
    for(int64_t i = 0; i < eCnt; i++) {
        auto [d,u,v] = edge[i];
        if(find(u) == find(v)) continue;

        uni(u,v);
        ans += sqrt(d);
        cnt++;
        if(cnt == n-1) break;
    }

    cout << fixed << setprecision(2) << ans;
}