#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[302][302];
int vis[302][302];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;
int n, m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int year = 0;
    while(true) {
        year++;
        // check ice melting
        int zero[303][303] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] <= 0) continue;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(board[nx][ny] > 0) continue;
                    zero[i][j]++;
                }
            }
        }
        // check number of ice
        int cnt1 = 0;
        int sx = -1, sy = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                board[i][j] = board[i][j] - zero[i][j];
                if(board[i][j] > 0) {
                    sx = i, sy = j;
                    cnt1++;
                }
            }
        }
        if(cnt1 == 0) {
            cout << 0;
            return 0;
        }
        // check number of ice section
        int cnt2 = 0;
        vis[sx][sy] = year;
        Q.push({sx,sy});
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            cnt2++;
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] <= 0 || vis[nx][ny] == year) continue;
                vis[nx][ny] = year;
                Q.push({nx,ny});
            }
        }
        if(cnt2 < cnt1) break;
    }
    cout << year;
}