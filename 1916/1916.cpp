#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using int64 = long long;
#define X first
#define Y second
#define INF 0x3f3f3f3f
const int MX = 10005;
priority_queue<pii,vector<pii>,greater<pii>> pq;
vector<pii> adj[MX];
int64_t d[MX];
int n, m;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int board[102][102];
bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void dijkstra(int st, int64_t* d) {
    fill(d+1, d+1+n*m, INF);
    d[st] = 0;
    pq.push({0,st});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
            d[nxt.Y] = d[cur.Y]+nxt.X;
            pq.push({d[nxt.Y],nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            char tmp;
            cin >> tmp;
            board[x][y] = tmp - '0';
        }
    }
    
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            int u = m * x + y;
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OOB(nx,ny)) continue;
                int v = m * nx + ny;
                adj[u].push_back({board[nx][ny],v});
            }
        }
    }

    dijkstra(0,d);
    cout << d[n*m-1];
}