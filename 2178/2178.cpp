#include <iostream>
using namespace std;

#define X first
#define Y second
char board[102][102];
int dist[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int, int> dat_t;
const int MX = 10005;
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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
    }
    
    dist[0][0] = 0;
    push({0, 0});
    while(!empty()) {
        pair<int, int> cur = front(); pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1 || board[nx][ny] != '1') continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            push({nx, ny});
        }
    }

    cout << dist[n - 1][m - 1] + 1;
}