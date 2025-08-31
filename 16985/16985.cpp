#include <bits/stdc++.h>
using namespace std;

#define INF (5*5*5*5*5)

int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

int board[4][5][5][5];
int maze[5][5][5];

int solve(){
    int dist[5][5][5] = {0,};
    if(maze[0][0][0] == 0 or maze[4][4][4] == 0) return INF;

    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    dist[0][0][0] = 1;
        while(!q.empty()){
        tuple<int,int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 6; dir++){
            int x, y, z;
            tie(x, y, z) = cur;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(0 > nx || 5 <= nx || 0 > ny || 5 <= ny || 0 > nz || 5 <= nz) continue;      
            if(maze[nx][ny][nz] == 0 || dist[nx][ny][nz] != 0) continue;
            if(nx == 4 && ny == 4 && nz == 4) return dist[x][y][z];
            dist[nx][ny][nz] = dist[x][y][z]+1;
            q.push({nx,ny,nz});
        }
    }
    return INF;
}

int ans = INF;
int order[5];
int used[5];
void func(int k) {
    if(k == 5) {
        for(int tmp = 0; tmp < 1024; tmp++){
            int brute = tmp;
            for(int i = 0; i < 5; i++){
            int dir = brute % 4;
            brute /= 4;
            for(int j = 0; j < 5; j++)
                for(int k = 0; k < 5; k++)
                maze[i][j][k] = board[dir][order[i]][j][k];        
            }
            ans = min(ans,solve());
        }
    }

    for(int i = 0; i < 5; i++) {
        if(!used[i]) {
            used[i] = 1;
            order[k] = i;
            func(k + 1);
            used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int k = 0; k < 5; k++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> board[0][k][i][j];
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                board[1][k][i][j] = board[0][k][j][4-i];
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                board[2][k][i][j] = board[1][k][j][4-i];
            }
        }
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                board[3][k][i][j] = board[2][k][j][4-i];
            }
        }
    }

    func(0);

    if(ans == INF) ans = -1;
    cout << ans;
}