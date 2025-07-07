#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool board[102][102];
bool vis[102][102];
vector<pair<int,int>> switchs[102][102];
queue<pair<int,int>> Q;
int n, m;
int ans;

void turnon(pair<int,int> sw) {
    // turn on switch
    if(!board[sw.X][sw.Y]) ans++;
    board[sw.X][sw.Y] = 1;
    // check sw room can visit
    if(vis[sw.X][sw.Y]) return;
    for(int dir = 0; dir < 4; dir++) {
        int ax = sw.X + dx[dir];
        int ay = sw.Y + dy[dir];
        if(ax < 0 || ax >= n || ay < 0 || ay >= n) continue;
        if(!board[ax][ay] || !vis[ax][ay]) continue;
        vis[sw.X][sw.Y] = 1;
        Q.push(sw);
        break;            
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x, y, a, b;
    while(m--) {
        cin >> x >> y >> a >> b;
        switchs[x-1][y-1].push_back({a-1,b-1});
    }

    ans = 1;
    board[0][0] = 1;
    vis[0][0] = 1;
    Q.push({0,0});
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();

        // turn on sw & check sw room can visit
        for(pair<int,int> sw : switchs[cur.X][cur.Y]) turnon(sw);
        // check adj rooms can visit
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!board[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }

    cout << ans;
}