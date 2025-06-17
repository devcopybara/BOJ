#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
bool vis[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;
int areas[10004];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int x1, y1, x2, y2;
    while(k--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = y1; i < y2; i++) {
            for(int j = x1; j < x2; j++) {
                vis[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;

            int area = 0;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            areas[cnt++] = area;
        }
    }

    sort(areas, areas + cnt);
    cout << cnt << '\n';
    for(int i = 0; i < cnt; i++) {
        cout << areas[i] << ' ';
    }
}