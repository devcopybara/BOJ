#include <iostream>
using namespace std;

#define X first
#define Y second
int n, m;
int board[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int, int> dat_t;
const int MX = 250005;
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
dat_t back() {
    return dat[tail - 1];
}
bool empty() {
    return head == tail;
}
int size() {
    return tail - head;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int mx = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0 && vis[i][j]) continue;
                        
            cnt++;
            vis[i][j] = 1;
            push({i, j});

            int area = 0;
            while(!empty()) {
                area++;
                pair<int, int> cur = front(); pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    push({nx,ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout << cnt << '\n' << mx;
}