#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int n;
string board1[102];
bool vis1[102][102];
string board2[102];
bool vis2[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;

void solve(string board[102], bool vis[102][102]) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vis[i][j]) continue;
            cnt++;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
        }
    }
    cout << cnt << ' ';
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board1[i];
        board2[i] = board1[i];
        for(int j = 0; j < n; j++)
            if(board2[i][j] == 'G')
                board2[i][j] = 'R';
    }

    solve(board1, vis1);
    solve(board2, vis2);
}