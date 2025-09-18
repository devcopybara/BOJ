// https://www.acmicpc.net/problem/17143
// time complex : 
// [1.낚시왕 이동] * [2.낚시] * [3.상어 이동]
// [100] * [100 + 100 * 100 * 100]
// 100,010,000 < 500,000,000

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int r, c, m;
int board[100][100];
int ans;
vector<tuple<int,int,int>> shark;

bool OOB(int x, int y) {
    return (x < 0 || x >= r || y < 0 || y >= c);
}

void fishing(int j) {
    for(int i = 0; i < r; i++) {
        if(board[i][j] != -1) {
            int s,d,z;
            tie(s,d,z) = shark[board[i][j]];
            ans += z;
            board[i][j] = -1;
            break;
        }
    }
}

void move() {
    int nboard[100][100];
    for(int i = 0; i < r; i++)
        fill(nboard[i], nboard[i] + c, -1);

    for(int x = 0; x < r; x++) {
        for(int y = 0; y < c; y++) {
            if(board[x][y] != -1) {
                int si = board[x][y];
                int s,d,z;
                tie(s,d,z) = shark[si];
                int nx = x, ny = y;
                for(int ss = 0; ss < s; ss++) {
                    if(OOB(nx + dx[d], ny + dy[d]))
                        d = d & 1 ? d - 1 : d + 1;
                    nx += dx[d], ny += dy[d];
                }
                shark[si] = {s,d,z};

                if(nboard[nx][ny] != -1) {
                    int s2,d2,z2;
                    tie(s2,d2,z2) = shark[nboard[nx][ny]];
                    if(z > z2) {
                        nboard[nx][ny] = si;
                    }
                }
                else {
                    nboard[nx][ny] = si;
                }
            }
        }
    }

    for(int x = 0; x < r; x++)
        for(int y = 0; y < c; y++)
            board[x][y] = nboard[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;

    for(int i = 0; i < r; i++)
        fill(board[i], board[i] + c, -1);

    for(int i = 0; i < m; i++) {
        int x,y,s,d,z;
        cin >> x >> y >> s >> d >> z;
        board[x-1][y-1] = i;
        if(d <= 2)
            s = s % (r * 2 - 2);
        else
            s = s % (c * 2 - 2);
        shark.push_back({s,d-1,z});
    }

    for(int j = 0; j < c; j++) {
        fishing(j);
        move();
    }
    cout << ans;
}