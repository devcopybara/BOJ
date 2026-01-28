// https://www.acmicpc.net/problem/4179

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x, y) 하나이며, 각 상태에서 필요한 정보는 ‘최단 거리’뿐이므로, dist[x][y] 형태의 2차원 배열이면 충분하다.

// 상태를 노드로 바꾼 순간이 언제인가?
// 이 문제에서는 BFS에서 큐에 들어가는 순간, 해당 상태의 최단 거리는 확정된다.

// 큐에 들어가는 정보는 “좌표”가 아니라 “의미”인가?
// 큐에 들어가는 것은 단순한 좌표가 아니라, ‘최단 거리가 확정되어 확장을 기다리는 상태’다.

// 이 문제가 DFS로 절대 안 되는 이유는?
// DFS는 최단 거리 불변식이 없으므로, 어떤 노드에 처음 도달했을 때 그것이 최단 거리라는 보장이 없다.
// 따라서 모든 경로를 탐색해야 하고, 이는 최단 거리 문제에 비효율적이다.

// 왜 시작점이 여러 개인데도 BFS를 한 번에 돌리면 안되나?
// 성질이 다른 시작점들은 서로 다른 큐에 넣고 별개의 BFS를 수행해야하므로,
// 성질이 다른 시작점들은 서로 다른 큐에 넣고 별도로 BFS를 수행한다.

// 왜 지훈이의 시작점을 먼저 BFS를 돌리면 안되나?
// 지훈이는 탈출하는데 불이 위치한 곳을 이동하지 못하는 제약이 있기 때문에
// 시간별 불의 위치를 먼저 알아야 시간별 지훈이의 이동 가능 위치를 확인하여 이동할 위치를 확정할 수 있다.

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MX = 1002;
char board[MX][MX];
int dist[MX][MX];
int dist2[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int,int>> q;
    queue<pair<int,int>> q2;

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            char tmp;
            cin >> tmp;
            board[x][y] = tmp;
            if(tmp == 'F') {
                dist[x][y] = 1;
                q.push({x,y});
            }
            if(tmp == 'J') {
                dist2[x][y] = 1;
                q2.push({x,y});
            }
        }
    }

    // 불의 시간별 확산 계산
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny]) continue;
            if(board[nx][ny] == '#') continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }

    // 지훈이의 시간별 이동 가능한 공간 계산 -> 탈출 가능 여부와 최단 탈출 시간 계산
    int ans = 0;

    while(!q2.empty()) {
        auto cur = q2.front(); q2.pop();
        if(cur.X == 0 || cur.X == n-1 || cur.Y == 0 || cur.Y == m-1) {
            ans = dist2[cur.X][cur.Y];
            break;
        }

        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist2[nx][ny]) continue;
            if(board[nx][ny] == '#') continue;
    
            if(dist[nx][ny] && dist2[cur.X][cur.Y]+1 >= dist[nx][ny]) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
            q2.push({nx,ny});
        }
    }
    
    if(ans) cout << ans;
    else cout << "IMPOSSIBLE";
}