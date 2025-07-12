#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[1502][1502];
bool vis[1502][1502];
queue<pair<int,int>> Q;
int n, m;
pair<int,int> L;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == 'L') {
                L = {i,j};
            }
        }
    }

    int ans = 0;
    while(1) {
        for(int i = 0; i < n; i++) {
            fill(vis[i], vis[i] + m, 0);
        }
        
        vis[L.X][L.Y] = 1;
        Q.push(L);
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny]) continue;
                if(board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    vis[nx][ny] = 1;
                    continue;
                }
                vis[nx][ny] = 1;
                Q.push({nx,ny});
                if(board[nx][ny] == 'L') {
                    cout << ans;
                    return 0;
                }
            }
        }

        ans++;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] || board[i][j] == 'X') continue;
                
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny]) continue;
                        if(board[nx][ny] == 'X') {
                            board[nx][ny] = '.';
                            vis[nx][ny] = 1;
                            continue;
                        }
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
    }
}