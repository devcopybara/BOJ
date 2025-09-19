// https://www.acmicpc.net/problem/17144
// time complex : 
// [시간] x ([배열 초기화] + [먼지 확산] + [공청기 작동] + [배열 복사])
// [1,000] x ([50 x 50] + [50 x 50 x 4] + [50 x 3 x 2] + [50 x 50])
// 15,300,000 < 500,000,000

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int r,c,t;
int board[50][50];
int nboard[50][50];
vector<pair<int,int>> airpurifier;

bool OOB(int x, int y) {
    return (x < 0 || x >= r || y < 0 || y >= c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == -1)
                airpurifier.push_back({i,j});
        }
    }
    // [시간]
    while(t--) {
        // [배열 초기화]
        for(int i = 0; i < r; i++)
            fill(nboard[i], nboard[i] + c, 0);
        // [먼지 확산]
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] <= 0) continue;

                int cnt = 0;
                int dust = board[i][j] / 5;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(OOB(nx,ny) || board[nx][ny] == -1) continue;
                    cnt++;
                    nboard[nx][ny] += dust;
                }
                nboard[i][j] += board[i][j] - dust * cnt;
            }
        }
        // [공청기 작동]
        // [공청기 작동1]
        auto cur = airpurifier[0];
        for(int i = cur.X; i > 0; i--)
            nboard[i][0] = nboard[i-1][0];
        for(int j = 0; j < c-1; j++)
            nboard[0][j] = nboard[0][j+1];
        for(int i = 0; i < cur.X; i++)
            nboard[i][c-1] = nboard[i+1][c-1];
        for(int j = c-1; j > 0; j--)
            nboard[cur.X][j] = nboard[cur.X][j-1];
        nboard[airpurifier[0].X][airpurifier[0].Y + 1] = 0;
        nboard[airpurifier[0].X][airpurifier[0].Y] = -1;
        // [공청기 작동2]
        cur = airpurifier[1];
        for(int i = cur.X; i < r-1; i++)
            nboard[i][0] = nboard[i+1][0];
        for(int j = 0; j < c-1; j++)
            nboard[r-1][j] = nboard[r-1][j+1];
        for(int i = r-1; i > cur.X; i--)
            nboard[i][c-1] = nboard[i-1][c-1];
        for(int j = c-1; j > 0; j--)
            nboard[cur.X][j] = nboard[cur.X][j-1];   
        nboard[airpurifier[1].X][airpurifier[1].Y + 1] = 0;
        nboard[airpurifier[1].X][airpurifier[1].Y] = -1;
        // [배열 복사]
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                board[i][j] = nboard[i][j];
    }

    int ans = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans += board[i][j];    
        }
    }
    cout << ans + 2;
}