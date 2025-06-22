#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102];
bool vis[102][102];
int dist[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n;
queue<pair<int,int>> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    // check section
    int sCnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 || vis[i][j]) continue;
            sCnt++;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = sCnt;                
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    // get startpoint
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j]) 
                Q.push({i,j});
    // check distance
    int ans = 10005;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            
            if(board[nx][ny] == board[cur.X][cur.Y])
                continue;
            else if(board[nx][ny] == 0) {
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
            else {
                ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);
            }
        }
    }
    cout << ans;
}