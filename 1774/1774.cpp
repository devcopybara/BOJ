// https://www.acmicpc.net/problem/1774
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MX = 1'002;
int n, m;
int coordi[MX][2];
vector<pii> adj[MX];
bool chk[MX];
priority_queue<pii,vector<pii>,greater<pii>> pq;
int cnt;
int get_coordi_dist(int u, int v) {
    int x = coordi[u][0]-coordi[v][0];
    int y = coordi[u][1]-coordi[v][1];
    return (int)100*sqrt(x*x+y*y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> coordi[i][0] >> coordi[i][1];
    }
    while(m--) {
        int u, v;
        cin >> u >> v;
        int w = get_coordi_dist(u,v);
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }


}