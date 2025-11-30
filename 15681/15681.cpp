// https://www.acmicpc.net/problem/15681
#include <bits/stdc++.h>
using namespace std;

int n,r,q;
vector<int> adj[100'005];
int p[100'005];
int tot[100'005];

// 정점 cur을 루트로 하는 서브트리에 속한 정점의 수를 반환
int dfs(int cur) {
    tot[cur] = 1;

    for(int nxt : adj[cur]) {
        if(nxt == p[cur]) continue;
        p[nxt] = cur;
        tot[cur] += dfs(nxt);
    }

    return tot[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> q;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r);

    while(q--) {
        int u;
        cin >> u;
        cout << tot[u] << '\n';
    }
} 