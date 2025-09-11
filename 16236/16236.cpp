#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

int n;
int board[20][20];

int sx, sy, sz = 2, cnt;

void hunting(int nx, int ny) {
    sx = nx, sy = ny, cnt++, board[nx][ny] = 0;
    if(cnt >= sz) cnt = 0, sz++;
}

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

bool cmp(int x1, int y1, int x2, int y2) {
    if(x1 == x2) return y1 < y2;
    return x1 < x2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 9) {
                sx = i, sy = j;
            }
            else {
                board[i][j] = tmp;
            }
        }
    }

    int tot = 0;
    while(1) {
        int tx = n, ty = n, td = 0;

        int dst[20][20];
        for(int i = 0; i < n; i++) fill(dst[i], dst[i] + n, 0);
        queue<pair<int,int>> q;

        dst[sx][sy] = 1;
        q.push({sx,sy});
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if(td && dst[cur.X][cur.Y] >= td)
                break;

            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx,ny) || dst[nx][ny] || board[nx][ny] > sz) continue;
                dst[nx][ny] = dst[cur.X][cur.Y] + 1;
                if(board[nx][ny] > 0 && board[nx][ny] < sz) {
                    td = dst[nx][ny];
                    if(!cmp(tx,ty,nx,ny))
                        tx = nx, ty = ny;
                }
                else {
                    q.push({nx,ny});
                }
            }
        }
        
        if(td) {
            tot += td - 1;
            hunting(tx,ty);
        }
        else {
            break;
        }
    }
    cout << tot;
}