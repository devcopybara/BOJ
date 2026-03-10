// https://www.acmicpc.net/problem/1261
#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

int n, m;
const int MX = 105;
const int INF= MX * 105;
vector<ti3> adj[MX][MX];
int dist[MX][MX];
priority_queue<ti3,vector<ti3>,greater<ti3>> pq;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int board[MX][MX];
bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
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
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(OOB(nx,ny)) continue;
                adj[x][y].push_back({board[nx][ny],nx,ny});
            }
        }
    }

    for(int x = 0; x < n; x++)
        fill(dist[x],dist[x]+m,INF);
    
    dist[0][0] = 0;
    pq.push({0,0,0});
    while(!pq.empty() && dist[n-1][m-1] == INF) {
        auto [d,x,y] = pq.top(); pq.pop();
        if(d != dist[x][y]) continue;
        for(auto [w,nx,ny] : adj[x][y]) {
            if(dist[nx][ny] > d + w) {
                dist[nx][ny] = d + w;
                pq.push({dist[nx][ny],nx,ny});
            }
        }
    }
    
    cout << dist[n-1][m-1];
}