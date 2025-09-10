#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n, l, r ;
int board[50][50];


bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

bool OOV(int a, int b) {
    return (abs(a-b)<l || abs(a-b)>r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int day = 0;
    while(1) {
        bool moved = false;

        bool vis[50][50];
        for(int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 1) continue;

                int tot = 0, cnt = 0;
                queue<pair<int,int>> p, q;
                vis[i][j] = 1;
                q.push({i,j});
                while(!q.empty()) {
                    auto cur = q.front(); q.pop();
                    cnt++; tot += board[cur.X][cur.Y]; p.push(cur);
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx,ny) || vis[nx][ny] || OOV(board[cur.X][cur.Y],board[nx][ny])) continue;
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                        moved = true;
                    }
                }
                while(!p.empty()) {
                    auto cur = p.front(); p.pop();
                    board[cur.X][cur.Y] = tot / cnt;
                }
            }
        }

        if(!moved) break;
        day++;
    }
    cout << day;
}