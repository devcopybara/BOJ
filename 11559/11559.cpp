#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;
stack<pair<int,int>> S;
char board[12][6];
int vis[12][6];
int n = 12, m =6;
int ans;
bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

bool IsConti(int t) {
    bool ret = false;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] != '.' && vis[i][j] != t) {
                int cnt = 0;
                vis[i][j] = t;
                Q.push({i,j});
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    S.push(cur);
                    cnt++;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx,ny)) continue;
                        if(vis[nx][ny] == t) continue;
                        if(board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = t;
                        Q.push({nx,ny});
                    }
                }

                if(cnt >= 4) {
                    ret = true;
                    while(!S.empty()) {
                        pair<int,int> cur = S.top(); S.pop();
                        board[cur.X][cur.Y] = '.';
                    }
                }
                else {
                    while(!S.empty()) S.pop();
                }
            }
        }
    }

    if(ret) {
        ans++;
        for(int j = 0; j < m; j++) {
            int k = n - 1;
            for(int i = n - 1; i >= 0; i--) {
                if(board[i][j] != '.') {
                    char tmp = board[i][j];
                    board[i][j] = '.';
                    board[k--][j] = tmp;
                }
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < n; i++)
        cin >> board[i];

    int t = 0;
    while(1) {
        bool isBreak = true;
        if(IsConti(++t)) isBreak = false;
        if(isBreak) break;
    }

    cout << ans;
}