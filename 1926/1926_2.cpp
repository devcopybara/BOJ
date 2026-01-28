// https://www.acmicpc.net/problem/1926

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x, y) 하나뿐이기 때문에, visited는 2차원이면 충분하다.

// 상태를 노드로 바꾼 순간이 언제인가?
// 이 문제에서는 애초에 ‘좌표 자체가 곧 상태이자 노드’다. 따라서 “상태를 노드로 바꾼 순간”이 따로 존재하지 않는다.

// 큐에 들어가는 정보는 “좌표”가 아니라 “의미”인가?
// 큐에 들어가는 것은 ‘좌표’처럼 보이지만, 실제로는 “같은 그림에 속한 미방문 픽셀”이라는 의미를 가진 노드다.

// 이 문제가 DFS로 절대 안 되는 이유는?
// 이 문제는 연결 요소의 크기만 필요하고, 거리·순서·최단경로가 전혀 필요 없기 때문에 DFS/BFS 모두 가능하다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MX = 502;
int board[MX][MX];
int vis[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int x = 0; x < n; x++)
        for(int y = 0; y < m; y++)
            cin >> board[x][y];

    int num = 0, mx = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(!board[x][y]) continue;
            if(vis[x][y]) continue;
            num++;

            queue<pair<int,int>> q;

            vis[x][y] = 1;
            q.push({x,y});
            int sz = 1;

            while(!q.empty()) {
                auto cur = q.front(); q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny]) continue;
                    if(!board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                    sz++;
                }
            }

            mx = max(mx,sz);
        }
    }
    cout << num << '\n' << mx;
}