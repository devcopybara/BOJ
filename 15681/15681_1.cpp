// https://www.acmicpc.net/problem/15681
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<int> adj[MX];
int tot[MX];

// 정점 cur을 루트로 하는 서브트리에 속한 정점의 수 반환
int dfs(int cur, int par) {
    int cnt = 1;
    for(int nxt : adj[cur]) {
        if(nxt == par) continue;
        cnt += dfs(nxt, cur);
    }
    return tot[cur] = cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r, 0);
    
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        cout << tot[x] << '\n';
    }
}