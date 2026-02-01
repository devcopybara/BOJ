#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[202][202];
int dist[32][202][202];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int dkx[8] = {2,1,-1,-2,-2,-1,1,2};
int dky[8] = {1,2,2,1,-1,-2,-2,-1};
queue<tuple<int,int,int>> Q;
int n, m, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    dist[k][0][0] = 1;
    Q.push({k,0,0});
    while(!Q.empty()) {
        int curK, curX, curY;
        tie(curK, curX, curY) = Q.front(); Q.pop();
        if(curK) {
            for(int dir = 0; dir < 8; dir++) {
                int nk = curK - 1;
                int nx = curX + dkx[dir];
                int ny = curY + dky[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] || dist[nk][nx][ny]) continue;
                dist[nk][nx][ny] = dist[curK][curX][curY] + 1;
                Q.push({nk,nx,ny});
            }
        }
        for(int dir = 0; dir < 4; dir++) {
            int nk = curK;
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] || dist[nk][nx][ny]) continue;
            dist[nk][nx][ny] = dist[curK][curX][curY] + 1;
            Q.push({nk,nx,ny});
        }
    }
    int ans = 1200000;
    for (int i = 0; i <= k; i++)
        if(dist[i][n-1][m-1]) 
            ans = min(ans,dist[i][n-1][m-1]);
    if (ans != 1200000) cout << ans-1;
    else cout << -1;
}