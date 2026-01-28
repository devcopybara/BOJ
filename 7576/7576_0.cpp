#include <iostream>
using namespace std;

typedef pair<int, int> dat_t;
const int MX = 1000005;
dat_t dat[MX];
int head, tail;
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

#define X first
#define Y second
int n, m;
int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) 
                push({i, j});
        }

    while(!empty()) {
        pair<int, int> cur = front(); pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny] != 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            board[nx][ny] = 1;
            push({nx, ny});
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
}