#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> dat_t;
const int MX = 1000005;
typedef struct queue_t {
    dat_t dat[MX];
    int head = 0, tail = 0;
    void push(dat_t x) {
        dat[tail++] = x;
    }
    void pop() {
        head++;
    }
    dat_t front() {
        return dat[head];
    }
    bool empty() {
        return head == tail;
    }
}queue_t;

#define X first
#define Y second
int n, m;
char board[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue_t Q1, Q2;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);    
    }

    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'F') {
                dist1[i][j] = 0;
                Q1.push({i, j});
            }
            else if(board[i][j] == 'J') {
                dist2[i][j] = 0;
                Q2.push({i, j});
            }                
        }
    }

    while(!Q1.empty()) {
        pair<int, int> cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    while(!Q2.empty()) {
        pair<int, int> cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
            if(dist1[nx][ny] != -1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}