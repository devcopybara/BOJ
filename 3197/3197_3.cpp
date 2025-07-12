#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[1502][1502];
int dist[1502][1502];
int vis[1502][1502];
queue<pair<int,int>> Q;
int n, m;
vector<pair<int,int>> L;
queue<pair<int,int>> LQ[2];
int cnt = 0;

void expendEdge(queue<pair<int,int>> &q, int i) {
    queue<pair<int,int>> nq;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] >= 0) continue;
            board[nx][ny] = '.';
            vis[nx][ny] = i;
            nq.push({nx,ny});
        }
    }
    q.swap(nq);
}

void makeQueue(queue<pair<int,int>> &q, int i, pair<int,int> sp) {
    int j = vis[sp.X][sp.Y];
    int d = dist[sp.X][sp.Y];

    vis[sp.X][sp.Y] = i;
    q.push(sp);
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] == i) continue;
            if(dist[nx][ny] < d - 1) continue;

        }
    }
}

void mergeQueue(queue<pair<int,int>> &q1, queue<pair<int,int>> &q2, int i) {
    while(!q2.empty()) {
        pair<int,int> cur = q2.front(); q2.pop();
        vis[cur.X][cur.Y] = i;
        q1.push(cur); 
    }
}

void mergeEdge(queue<pair<int,int>> &q, int i) {
    queue<pair<int,int>> nq;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] == i) continue;
            if(vis[nx][ny] == -1) continue;
            
            queue<pair<int,int>> _q;

            makeQueue(_q, i, {nx,ny});
            mergeQueue(q, _q, i);
        }
        nq.push(cur);
    }
    q.swap(nq);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == 'L') {
                L.push_back({i,j});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + m, -1);
        fill(vis[i], vis[i] + m, -1);
    }

    int ans = 0;
    // make edge
    for(int i = 0; i < 2; i++) {
        dist[L[i].X][L[i].Y] = ans;
        vis[L[i].X][L[i].Y] = i;
        Q.push(L[i]);
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny] >= ans) continue;

                if(board[nx][ny] == 'X') {
                    LQ[i].push(cur);
                    continue;
                }
                vis[nx][ny] = cnt;
                dist[nx][ny] = ans;
                Q.push({nx,ny});
            }
        }
        cnt++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] != ans - 1 || board[i][j] == 'X') continue;
            
            dist[i][j] = ans;
            Q.push({i,j});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(dist[nx][ny] >= ans) continue;
                    
                    if(board[nx][ny] == 'X') {
                        continue;
                    }
                    vis[nx][ny] = cnt;
                    dist[nx][ny] = ans;
                    Q.push({nx,ny});
                }
            }
            cnt++;
        }
    }
        
    while(!LQ[1].empty()) {
        ans++;
        
        // check connected LQ[0] LQ[1]

    }
}