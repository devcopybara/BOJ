#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[1502][1502];
int vis[1502][1502];
int n, m;
queue<pair<int,int>> Q[1502*1502/2];
int qCnt;

void makeEdge(queue<pair<int,int>> &q, int i) {
    queue<pair<int,int>> nq;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] >= 0) continue;
            if(board[nx][ny] == 'X') {
                nq.push(cur);
            }
            else {
                vis[nx][ny] = i;
                q.push({nx,ny});
            }
        }
    }
    q.swap(nq);
}

void expendEdge(queue<pair<int,int>> &q, int i) {
    queue<pair<int,int>> nq;
    while(!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] >= 0) continue;
            board[nx][ny] = '.';
            vis[nx][ny] = i;
            nq.push({nx,ny});
        }
    }
    q.swap(nq);
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
        bool isEdge = 0;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] == i) continue;
            if(vis[nx][ny] == -1) {
                isEdge = 1;
                continue;
            }
            
            mergeQueue(q, Q[vis[nx][ny]], i);
        }
        if(isEdge) {
            nq.push(cur);
        }
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
                vis[i][j] = qCnt;
                Q[qCnt].push({i,j});
                qCnt++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        fill(vis[i], vis[i] + m, -1);
    }

    makeEdge(Q[0], 0);
    makeEdge(Q[1], 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'X' || vis[i][j]) continue;

            vis[i][j] = qCnt;
            Q[qCnt].push({i,j});
            makeEdge(Q[qCnt],qCnt);
            qCnt++;
        }
    }

    int ans = 0;
    while(!Q[1].empty()) {
        for(int i = 0; i < qCnt; i++) {
            expendEdge(Q[i], i);
        }
        for(int i = 0; i < qCnt; i++) {
            mergeEdge(Q[i], i);
        }
        ans++;
    }
    cout << ans;
}