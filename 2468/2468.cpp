#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[102][102];
int vis[102][102];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int max_height = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int height;
            cin >> height;
            board[i][j] = height;
            max_height = max(max_height, height);
        }
    }

    int max_cnt = 1;
    for(int h = 1; h < max_height; h++) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] <= h || vis[i][j] == h) continue;
                cnt++;
                vis[i][j] = h;
                Q.push({i,j});
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(board[nx][ny] <= h || vis[nx][ny] == h) continue;
                        vis[nx][ny] = h;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt;
}