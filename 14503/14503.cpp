#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n, m, x, y, d;
int board[50][50];

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    bool stopped = false;
    while(!stopped) {
        // case1
        if(board[x][y] == 0) {
            board[x][y] = 2;
            ans++;
        }
        
        bool moved = false;
        for(int dd = 0; dd < 4; dd++) {
            int nd = (d + 3 - dd) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(OOB(nx,ny) || board[nx][ny] != 0) continue;
            // case3
            d = nd;
            x = nx;
            y = ny;
            moved = true;
            break;
        }

        if(moved == false) {
            // case2
            int bd = (d + 2) % 4;
            int bx = x + dx[bd];
            int by = y + dy[bd];
            // case2_2
            if(OOB(bx,by) || board[bx][by] == 1) stopped = true;
            // case2_1
            x = bx;
            y = by;
        }
    }
    cout << ans;
}