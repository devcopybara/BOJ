#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[302][302];
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int tc, l;
int sx, sy;
int ex, ey;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--) {
        cin >> l;
        for(int i = 0; i < l; i++) fill(dist[i], dist[i] + l, -1);
        cin >> sx >> sy;
        cin >> ex >> ey;
        queue<pair<int,int>> Q;

        dist[sx][sy] = 0;
        Q.push({sx,sy});
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            if(cur.X == ex && cur.Y == ey) {
                cout << dist[cur.X][cur.Y] << '\n';
                break;
            }
            for(int dir = 0; dir < 8; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
}