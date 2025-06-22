#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102];
bool vis[102][102];
int dist[102][102];
int section[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;
queue<pair<int,int>> Q1;
queue<tuple<int,int,int>> Q2;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    // check edge
    int sCnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;

            sCnt++;

            vis[i][j] = 1;
            Q1.push({i,j});
            while(!Q1.empty()) {
                pair<int,int> cur = Q1.front(); Q1.pop();
                section[cur.X][cur.Y] = sCnt;
                if(board[cur.X][cur.Y] == 0) {
                    dist[cur.X][cur.Y] = 1;
                    Q2.push({cur.X,cur.Y,sCnt});
                    continue;
                }
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q1.push({nx,ny});
                }
            }
        }
    }
    // check distance
    int ans = 10005;
    while(!Q2.empty()) {
        int curX,curY,curS;
        tie(curX,curY,curS) = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if(section[nx][ny] == curS)
                continue;
            else if(section[nx][ny] == 0) {
                section[nx][ny] = curS;
                dist[nx][ny] = dist[curX][curY] + 1;
                Q2.push({nx,ny,curS});
            }
            else {
                ans = min(ans, dist[nx][ny] + dist[curX][curY]);
            }
        }
    }
    cout << ans;
}