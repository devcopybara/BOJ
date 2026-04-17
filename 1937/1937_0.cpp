// https://www.acmicpc.net/problem/1937
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int64_t dx[4] = {0,1,0,-1};
int64_t dy[4] = {1,0,-1,0};

const int64_t MX = 502;
int64_t board[MX][MX];
int64_t d[MX][MX];

int64_t n;
int64_t OOB(int64_t x,int64_t y) {
    return (x >= n || x < 0 || y >= n || y <0);
}

int64_t getD(int64_t x,int64_t y) {
    if(d[x][y]) return d[x][y];

    int64_t nd = 1;
    for(int64_t dir = 0; dir < 4; dir++) {
        int64_t nx = x+dx[dir], ny = y+dy[dir];
        if(OOB(nx,ny)) continue;
        if(board[nx][ny] <= board[x][y]) continue;
        nd = max(nd, getD(nx,ny)+1);
    }
    d[x][y] = nd;

    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int64_t x = 0; x < n; x++) for(int64_t y = 0; y < n; y++) cin >> board[x][y];
    
    int64_t ans = 0;
    for(int64_t x = 0; x < n; x++) for(int64_t y = 0; y < n; y++) ans=max(ans,getD(x,y));
    cout << ans;
}