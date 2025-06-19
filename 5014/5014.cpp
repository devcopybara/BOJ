#include <bits/stdc++.h>
using namespace std;

int dist[1000002];
queue<int> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    fill(dist, dist + f + 1, -1);
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int curX = Q.front(); Q.pop();
        if(curX == g) {
            cout << dist[curX];
            return 0;
        }
        for(int dx : {u, -d}) {
            int nx = curX + dx;
            if(nx < 1 || nx > f) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[curX] + 1;
            Q.push(nx);
        }
    }
    cout << "use the stairs";
}