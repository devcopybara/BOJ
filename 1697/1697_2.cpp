// https://www.acmicpc.net/problem/1697

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 오직 좌표 (x) 하나이며, 각 상태에서 필요한 정보는 ‘최단 거리’뿐이므로, dist[x] 형태의 1차원 배열이면 충분하다.

// 상태를 노드로 바꾼 순간이 언제인가?
// 이 문제에서는 BFS에서 큐에 들어가는 순간, 해당 상태의 최단 거리는 확정된다.

// 큐에 들어가는 정보는 “좌표”가 아니라 “의미”인가?
// 큐에 들어가는 것은 단순한 좌표가 아니라, ‘최단 거리가 확정되어 확장을 기다리는 상태’다.

// 이 문제가 DFS로 절대 안 되는 이유는?
// DFS는 최단 거리 불변식이 없으므로, 어떤 노드에 처음 도달했을 때 그것이 최단 거리라는 보장이 없다.
// 따라서 모든 경로를 탐색해야 하고, 이는 최단 거리 문제에 비효율적이다.


#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;
int dist[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int mx = max(n,k);
    queue<int> q;

    dist[n] = 1;
    q.push(n);

    while(!q.empty()) {
        auto curX = q.front(); q.pop();
        if(curX == k) break;

        for(int nx : {curX*2, curX+1, curX-1}) {
            if(nx < 0 || nx > mx + 1) continue;
            if(dist[nx]) continue;
            dist[nx] = dist[curX]+1;
            q.push(nx);
        }
    }

    cout << dist[k]-1;
}