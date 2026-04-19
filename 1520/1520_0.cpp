// https://www.acmicpc.net/problem/1520

// d[x][y] : (x,y)에서 출발해서 (n,m)까지 항상 내리막길로만 이동하는 경로의 개수

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MX = 502;
const int INF=MX*MX;
int board[MX][MX];
int d[MX][MX];

int n, m;
int OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int getD(int x, int y) {
    if(d[x][y] >= 0) return d[x][y];

    d[x][y] = 0;

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(OOB(nx,ny)) continue;
        if(board[nx][ny] >= board[x][y]) continue;
        d[x][y] += getD(nx,ny);
    }

    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) fill(d[i],d[i]+m,-1);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> board[i][j];

    d[n-1][m-1] = 1;
    cout << getD(0,0);
}