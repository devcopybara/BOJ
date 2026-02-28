// https://www.acmicpc.net/problem/3197

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int MX = 1502;
char board[MX][MX];
int vis[MX][MX];
int dist[MX][MX];

int n, m;
void extand(int x, int y, int c, queue<pair<int,int>>& nq, bool isnq) {
    queue<pair<int,int>> q;

    vis[x][y] = c;
    q.push({x,y});

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] == vis[cur.X][cur.Y]) continue;
            if(board[nx][ny] == 'X') {
                vis[nx][ny] = c;
                if(isnq && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[cur.X][cur.Y]+1;
                    nq.push({nx,ny});
                }
                continue;
            }
            vis[nx][ny] = c;
            q.push({nx,ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pair<int,int>> v;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            char tmp;
            cin >> tmp;
            board[x][y] = tmp;
            if(tmp == 'L') {
                v.push_back({x,y});
            }
        }
    }

    queue<pair<int,int>> nq;

    int cnt = 0;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            if(board[x][y] == 'X') continue;
            if(vis[x][y]) continue;
            cnt++;

            extand(x,y,cnt,nq,1);
        }
    }

    int day = 0;
    while(!nq.empty()) {
        day++;

        int sz = nq.size();
        for(int i = 0; i < sz; i++) {
            auto cur = nq.front(); nq.pop();
            board[cur.X][cur.Y] = '.';

            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;


                if(board[nx][ny] != 'X') {
                    if(vis[nx][ny] != vis[cur.X][cur.Y]) extand(nx,ny,vis[cur.X][cur.Y],nq,0);
                    continue;
                }
                
                if(dist[nx][ny]) continue;

                vis[nx][ny] = vis[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                nq.push({nx,ny});
            }
        }

        if(vis[v[0].X][v[0].Y] == vis[v[1].X][v[1].Y]) {
            break;
        }
    }
    cout << day;
}