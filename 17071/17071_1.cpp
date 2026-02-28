// https://www.acmicpc.net/problem/17071

// visited 배열의 차원은 왜 이만큼인가?
// 이 문제에서 ‘상태(state)’는 좌표 (n')와 좌표 (k') 이며, 
// 좌표 (n') 에 필요한 정보는 ‘x좌표에 홀수/짝수 시간에 도달한 최단 시간’뿐이므로, dist[x][2] 형태의 2차원 배열이면 충분하다. 
// 좌표 (k') 에 필요한 정보는 ‘좌표 (k)’와 ‘경과 시간’으로 구할 수 있다.

// 상태를 노드로 바꾼 순간이 언제인가?
// 이 문제에서는 BFS에서 큐에 들어가는 순간, 해당 상태의 최단 거리는 확정된다.

// 큐에 들어가는 정보는 “좌표”가 아니라 “의미”인가?
// 큐에 들어가는 것은 단순한 좌표가 아니라, ‘최단 거리가 확정되어 확장을 기다리는 상태’와 ‘홀/짝수 최단 거리는 홀/짝수 시간마다 다시 해당 좌표에 존재 가능한 상태’다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 500'002;
int dist[2][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }

    fill(dist[0],dist[0]+MX,-1);
    fill(dist[1],dist[1]+MX,-1);
    
    int time = 0;
    int mx = 500'000;

    queue<int> q;
    dist[0][n] = 0;
    q.push(n);

    while(!q.empty()) {
        time++;
        // soobin move
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            auto curX = q.front(); q.pop();

            for(int nx : {curX*2, curX+1, curX-1}) {
                if(nx < 0 || nx > mx) continue;
                if(dist[time&1][nx] != -1) continue;
                dist[time&1][nx] = time;
                q.push(nx);
            }
        }
        // dongsang move
        k += time;
        if(k > mx) break;
        if(dist[time&1][k] != -1) {
            cout << time;
            return 0;
        }
    }

    cout << -1;
}