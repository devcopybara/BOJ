// https://www.acmicpc.net/problem/2178

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x, y) 하나이며, 각 상태에서 필요한 정보는 ‘최단 거리’뿐이므로, dist[x][y] 형태의 2차원 배열이면 충분하다.
// =>
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x, y) 하나이며, 각 상태에서 필요한 정보는 ‘한 개의 벽을 부쉈는지 여부’와 ‘최단 거리’뿐이므로, 
// 1. dist[x][y] 형태의 2차원 배열 -> {‘한 개의 벽을 부쉈는지 여부’, ‘최단 거리’} 저장 : 한 개의 벽을 부쉈는지 여부에 따라 2개의 최단거리 데이터 저장 필요
// 2. dist[x][y][‘한 개의 벽을 부쉈는지 여부’] 형태의 3차원 배열 -> ‘최단 거리’ 저장 : 기존과 같이 각 상태에서 필요한 정보는 ‘최단 거리’뿐
// =>
// 이 문제에서 ‘상태(state)’는 좌표 (x, y)과 ‘한 개의 벽을 부쉈는지 여부’ 이며, 각 상태에서 필요한 정보는 ‘최단 거리’뿐이므로, dist[x][y][k] 형태의 3차원 배열이면 충분하다. 

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

const int MX = 1002;
char board[MX][MX];
int dist[MX][MX][2];

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

    queue<tuple<int,int,int>> q;

    dist[0][0][0] = 1;
    q.push({0,0,0});

    int ans = -1;
    while(!q.empty()) {
        auto [curX,curY,curK] = q.front(); q.pop();
        if(curX == n-1 && curY == m-1) {
            ans = dist[curX][curY][curK];
            break;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nk = curK;
            // OOB
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // board[nx][ny] : Wall, Check Wall Breaks Count
            if(board[nx][ny] == 1 && nk == 1) continue; // Wall Breaks Count 1 -> PASS
            if(board[nx][ny] == 1) nk += 1; // Wall Breaks Count 0 -> Using Wall Breaks Count
            // visited
            if(dist[nx][ny][nk]) continue;
            
            dist[nx][ny][nk] = dist[curX][curY][curK]+1;
            q.push({nx,ny,nk});
        }
    }
    cout << ans;
}