#include <iostream>
using namespace std;

const int MX = 2505;
typedef pair<int,int> dat_t;
typedef struct queue_t{
    dat_t dat[MX];
    int head = 0, tail = 0;
    void init() {
        head = 0, tail = 0;
    }
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
int t, n, m, k;
int board[52][52];
bool vis[52][52];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue_t Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        
        for(int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }

        for(int x, y, i = 0; i < k; i++) {
            cin >> x >> y;
            board[x][y] = 1;
        }

        int cnt = 0;
        Q.init();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 0 || vis[i][j]) continue;
                cnt++;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}