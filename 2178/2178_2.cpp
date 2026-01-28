// https://www.acmicpc.net/problem/2178

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x, y) 하나이며, 각 상태에서 필요한 정보는 ‘최단 거리’뿐이므로, dist[x][y] 형태의 2차원 배열이면 충분하다.

// 상태를 노드로 바꾼 순간이 언제인가?
// 이 문제에서는 BFS에서 큐에 들어가는 순간, 해당 상태의 최단 거리는 확정된다.

// 큐에 들어가는 정보는 “좌표”가 아니라 “의미”인가?
// 큐에 들어가는 것은 단순한 좌표가 아니라, ‘최단 거리가 확정되어 확장을 기다리는 상태’다.

// 이 문제가 DFS로 절대 안 되는 이유는?
// DFS는 최단 거리 불변식이 없으므로, 어떤 노드에 처음 도달했을 때 그것이 최단 거리라는 보장이 없다.
// 따라서 모든 경로를 탐색해야 하고, 이는 최단 거리 문제에 비효율적이다.

#include <bits/stdc++.h>
using namespace std;
 
#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MX = 102;
int board[MX][MX];
int dist[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            char ch;
            cin >> ch;
            board[x][y] = ch - '0';
        }
    }
            

    queue<pair<int,int>> q;

    dist[0][0] = 1;
    q.push({0,0});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny]) continue;
            if(!board[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    cout << dist[n-1][m-1];
}