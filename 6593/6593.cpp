#include <bits/stdc++.h>
using namespace std;

char board[32][32][32];
int dist[32][32][32];
int dz[6] = {0,0,0,0,1,-1};
int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int l, n, m;
    while(1) {
        cin >> l >> n >> m;
        if(l == 0 && n == 0 && m == 0) break;

        queue<tuple<int,int,int>> Q;
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < m; k++) {
                    char tmp;
                    cin >> tmp;
                    board[i][j][k] = tmp;
                    if(tmp == 'S') {
                        dist[i][j][k] = 0;
                        Q.push({i,j,k});
                    }
                    else if(tmp == '#') {
                        dist[i][j][k] = 0;
                    }
                    else {
                        dist[i][j][k] = -1;
                    }
                }
            }
        }
        
        bool isTrapped = true;
        while(!Q.empty()) {
            int curZ, curX, curY;
            tie(curZ, curX, curY) = Q.front(); Q.pop();
            if(board[curZ][curX][curY] == 'E') {
                cout << "Escaped in " << dist[curZ][curX][curY] << " minute(s).\n";
                isTrapped = false;
                break;
            }
            for(int dir = 0; dir < 6; dir++) {
                int nz = curZ + dz[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if(nz < 0 || nz >= l || nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nz][nx][ny] >= 0) continue;
                dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
                Q.push({nz,nx,ny});
            }
        }
        if(isTrapped) cout << "Trapped!\n";
    }
}