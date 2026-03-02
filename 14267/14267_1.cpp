#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<int> ch[MX];
int tmp[MX];
int ans[MX];

void bfs(int root) {
    queue<int> q;
    q.push(root);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : ch[cur]) {
            q.push(nxt);
            ans[nxt] = tmp[nxt] + ans[cur];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int j;
        cin >> j;
        ch[j].push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int j, w;
        cin >> j >> w;
        tmp[j] += w;
    }

    bfs(1);

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}