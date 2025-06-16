#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int tc, w, h;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--) {
        queue<pair<int,int>> Q1, Q2;

        cin >> w >> h;
        for(int i = 0; i < h; i++) {
            cin >> board[i];
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '*') {
                    dist1[i][j] = 0;
                    Q1.push({i, j});
                }
                else if(board[i][j] == '@') {
                    dist2[i][j] = 0;
                    Q2.push({i,j});
                }
            }
        }

        while(!Q1.empty()) {
            pair<int,int> cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
                dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
                Q1.push({nx,ny});
            }
        }

        int ans = 0;
        while(!Q2.empty() && ans == 0) {
            pair<int,int> cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    ans = dist2[cur.X][cur.Y] + 1;
                    break;
                }
                if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
                if(dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
                dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
                Q2.push({nx,ny});
            }
        }
        if(ans) cout << ans << '\n';
        else cout << "IMPOSSIBLE\n";
    }
}