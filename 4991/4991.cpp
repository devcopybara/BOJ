// https://www.acmicpc.net/problem/4991
// time complex : 
// [더러운칸 방문 순서] x 10 x [더러운칸 방문 거리 계산]
// [10!] x [10] x 

#include <bits/stdc++.h>
using namespace std;

#define INF 5000

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int w, h;
char board[20][20];
int vis[20][20];
int sx, sy;
vector<pair<int,int>> dirty_cells;

bool OOB(int x, int y) {
    return (x < 0 || x >= h || y < 0 || y >= w);
}

int min_s2f_dist[20][20][20][20];

int get_min_s2f_dist(int sx, int sy, int fx, int fy) {
    if(min_s2f_dist[sx][sy][fx][fy] > 0) {
        return min_s2f_dist[sx][sy][fx][fy];
    }

    for(int i = 0; i < h; i++) 
        fill(vis[i], vis[i] + w, -1);
    queue<pair<int,int>> q;

    vis[sx][sy] = 0;
    q.push({sx,sy});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx,ny) || vis[nx][ny] != -1 || board[nx][ny] == 'x') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            q.push({nx,ny});
            if(nx == fx && ny == fy) {
                min_s2f_dist[sx][sy][fx][fy] = vis[nx][ny];
                return min_s2f_dist[sx][sy][fx][fy];
            }
        }
    }
    min_s2f_dist[sx][sy][fx][fy] = -1;
    return min_s2f_dist[sx][sy][fx][fy];
}

int get_min_tot_dist(vector<int> orders, int sx, int sy) {
    int dist = 0;
    for(int order : orders) {
        int fx = dirty_cells[order].X;
        int fy = dirty_cells[order].Y;
        
        dist += get_min_s2f_dist(sx, sy, fx, fy);
        if(dist >= INF)
            return INF;
        if(min_s2f_dist[sx][sy][fx][fy] == -1) 
            return -1;

        sx = fx;
        sy = fy;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> w >> h;
        if(w == 0) break;

        dirty_cells.clear();
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                char tmp;
                cin >> tmp;
                board[i][j] = tmp;
                if(tmp == '*')
                    dirty_cells.push_back({i,j});
                else if(tmp == 'o')
                    sx = i, sy = j;
            }
        }
        memset(min_s2f_dist,0,sizeof(min_s2f_dist));

        int ans = INF;
        vector<int> orders;
        int sz = dirty_cells.size();
        for(int i = 0; i < sz; i++)
            orders.push_back(i);
        do {
            ans = min(ans, get_min_tot_dist(orders, sx, sy));
            if(ans == -1)
                break;
        }while(next_permutation(orders.begin(), orders.end()));
        cout << ans << '\n';
    }
}