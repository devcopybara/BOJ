#include <bits/stdc++.h>
using namespace std;


int n, m;
int board[8][8];
pair<int,int> arr[64];
int aCnt;
int ans;
int cnt;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int sizes[6] = {0,4,2,4,4,1};
int lens[6] = {0,1,2,2,3,4};
int dirs[6][4] = {{},{0},{0,2},{0,1},{0,1,2},{0,1,2,3}};

bool OOB(int a, int b) {
    return a < 0 || a >= n || b < 0 || b >= m;
}
void check(pair<int,int> cur, int dir, int type, int len) {
    for(int i = 0; i < len; i++) {
        int cDir = (dirs[type][i] + dir) & 3; // % 4;
        int nx = cur.X + dx[cDir];
        int ny = cur.Y + dy[cDir];
        while(!OOB(nx,ny) && board[nx][ny] != 6) {
            if(board[nx][ny] == 0) {
                cnt--;
            }
            if(board[nx][ny] <= 0) {
                board[nx][ny] -= 1;
            }
            nx += dx[cDir]; 
            ny += dy[cDir];
        }
    }
}
void uncheck(pair<int,int> cur, int dir, int type, int len) {
    for(int i = 0; i < len; i++) {
        int cDir = (dirs[type][i] + dir) & 3; // % 4;
        int nx = cur.X + dx[cDir];
        int ny = cur.Y + dy[cDir];
        while(!OOB(nx,ny) && board[nx][ny] != 6) {
            if(board[nx][ny] == -1) {
                cnt++;
            }
            if(board[nx][ny] < 0) {
                board[nx][ny] += 1;
            }
            nx += dx[cDir]; 
            ny += dy[cDir];
        }
    }
}

void func(int k) {
    if(k == aCnt) {
        ans = min(ans, cnt);
        return;
    }

    pair<int,int> cur = arr[k];
    int type = board[cur.X][cur.Y];
    int size = sizes[type];
    int len = lens[type];

    for(int dir = 0; dir < size; dir++) {
        check(cur, dir, type, len);
        func(k + 1);
        uncheck(cur, dir, type, len);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ans = n * m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp > 0) {
                ans--;
                if(tmp < 6) arr[aCnt++] = {i,j};
            }
        }
    }
    cnt = ans;
    func(0);
    cout << ans;
}