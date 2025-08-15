#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n, m, g, r;
int garden[50][50];
int board[50][50];
int dist[50][50];
int ans;

int pCnt;
pair<int,int> pos[2500];
int arr[10];
int arr2[5];
queue<pair<int,int>> Q;

void func3() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] = garden[i][j];
            dist[i][j] = -1;
        }
    }

    for(int i = 0; i < g + r; i++) {
        pair<int,int> cur = pos[arr[i]];
        board[cur.X][cur.Y] = 4;
        dist[cur.X][cur.Y] = 0;
        Q.push(cur);
    }
    for(int i = 0; i < g; i++) {
        pair<int,int> cur = pos[arr[arr2[i]]];
        board[cur.X][cur.Y] = 3;
    }

    int fCnt = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        if(board[cur.X][cur.Y] == -1) {
            fCnt++;
            continue;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] <= 0) continue;
            if(dist[nx][ny] == -1) {
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
            else {
                if(dist[nx][ny] <= dist[cur.X][cur.Y]) continue;
                if(board[nx][ny] != board[cur.X][cur.Y]) board[nx][ny] = -1;
            }
        }
    }
    ans = max(ans, fCnt);
}

void func2(int k) {
    if(k == g) {
        func3();
        return;
    }
    int s = k == 0 ? 0 : arr2[k - 1] + 1;
    for(int i = s; i < g + r; i++) {
        arr2[k] = i;
        func2(k + 1);
    }
}

void func(int k) {
    if(k == g + r) {
        func2(0);
        return;
    }
    int s = k == 0 ? 0 : arr[k - 1] + 1;
    for(int i = s; i < pCnt; i++) {
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            garden[i][j] = tmp;
            if(tmp == 2) {
                pos[pCnt++] = {i,j};
            }
        }
    }

    func(0);
    cout << ans;
}