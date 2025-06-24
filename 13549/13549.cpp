#include <bits/stdc++.h>
using namespace std;

int dist[100002];
deque<int> Q;
int n, k;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    if(k == n) {
        cout << 0;
        return 0;
    }
    else if(k < n) {
        cout << n - k;
        return 0;
    }

    int m = k + 1;
    fill(dist, dist + m + 1, -1);

    for(int i = n; i <= m; i *= 2) {
        dist[i] = 0;
        Q.push_back(i);
    }

    while(!Q.empty() && dist[k] == -1) {
        int curX = Q.front(); Q.pop_front();
        for(int i = curX * 2; i <= m; i *= 2) {
            if(dist[i] >= 0) continue;
            dist[i] = dist[curX];
            Q.push_front(i);
        }
        for(int nx : {curX - 1, curX + 1}) {
            if(nx < 0 || nx > m) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[curX] + 1;
            Q.push_back(nx);
        }
    }

    cout << dist[k];
}