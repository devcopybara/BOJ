#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 20) + 1;
int tried[MX];
int dist[MX];
int n, m;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(dist, dist + n + 1, -1);
    queue<int> Q;

    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        tried[i] = tmp;
        dist[tmp] = 0;
        Q.push(tmp);
    }

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int bit = 1; bit <= n; bit <<= 1) {
            int nx = cur ^ bit;
            if(nx > n) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans << '\n';
}
