#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[302][302];
int vis[302][302];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q1;
queue<tuple<int,int,int>> Q2;
int n, m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int val;
            cin >> val;
            board[i][j] = val;
            if(val) Q1.push({i,j});
        }
    }

    int year = 0;
    while(!Q1.empty()) {
        year++;
        // check melting
        while(!Q1.empty()) {
            pair<int,int> cur = Q1.front(); Q1.pop();
            int ice = board[cur.X][cur.Y];
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny]) continue;
                ice--;
            }
            Q2.push({cur.X,cur.Y,ice>0?ice:0});
        }
        while(!Q2.empty()) {
            int curX, curY, ice;
            tie(curX,curY,ice) = Q2.front(); Q2.pop();
            board[curX][curY] = ice;
            if(ice) Q1.push({curX,curY});
        }
        
        if(Q1.size() == 0) {
            year = 0;
            break;
        }

        // check number of section
        int cnt = 0;
        queue<pair<int,int>> Q;
        pair<int,int> cur = Q1.front();
        vis[cur.X][cur.Y] = year;
        Q.push(cur);
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            cnt++;
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == 0 || vis[nx][ny] == year) continue;
                vis[nx][ny] = year;
                Q.push({nx,ny});
            }
        }

        if(cnt < Q1.size()) {
            break;
        }
    }
    cout << year;
}