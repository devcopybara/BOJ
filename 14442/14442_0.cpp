#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[1002][1002];
int dist[12][1002][1002];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<tuple<int,int,int>> Q;
int n, m, k = 1;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()) {
        int curK,curX,curY;
        tie(curK,curX,curY) = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '1') {
                if(curK == k) continue;
                if(dist[curK+1][nx][ny]) continue;
                dist[curK+1][nx][ny] = dist[curK][curX][curY] + 1;
                Q.push({curK+1,nx,ny});
            }
            else {
                if(dist[curK][nx][ny]) continue;
                dist[curK][nx][ny] = dist[curK][curX][curY] + 1;
                Q.push({curK,nx,ny});
            }
        }
    }
    int ans = 1000005;
    for(int i = 0; i <= k; i++) {
        if(dist[i][n-1][m-1]) {
            ans = min(ans, dist[i][n-1][m-1]);
        }
    }
    if(ans != 1000005) {
        cout << ans;
    }
    else {
        cout << -1;
    }
}