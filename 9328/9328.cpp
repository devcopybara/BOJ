#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char board[102][102];
bool vis[102][102];
vector<pair<int,int>> door[26];
int t, n, m;
queue<pair<int,int>> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        fill(board, board + 10004, 0);
        fill(vis, vis + 10004, 0);
        fill(door, door + 26, 0);
        // set board
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char tmp;
                cin >> tmp;
                board[i][j] = tmp;
                if(tmp >= 'A' && tmp <= 'Z') {
                    door[tmp-'A'].push_back({i,j});
                }
            }
        }
        // set key
        string keys;
        cin >> keys;
        if(keys != "0") {

        }
        // set start points
        for(int i = 1; i < n-1; i++) {
            if(board[0][i] == '.') {
                vis[0][i] = 1;
                Q.push({0,i});
            }
            if(board[m-1][i] == '.') {
                board[m-1][i] = 1;
                Q.push({m-1,i});
            }
        }
        for(int i = 1; i < m-1; i++) {
            if(board[i][0] == '.') {
                vis[i][0] = 1;
                Q.push({i,0});
            }
            if(board[i][n-1] == '.') {
                vis[i][n-1] = 1;
                Q.push({i,n-1});
            }
        }
        // get answer
        int ans = 0;
        while(!Q.empty()) {
            pair<int,int> cur = Q.front(); Q.pop();
            if(board[cur.X][cur.Y] == '$') ans++;

            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(board[nx][ny] == '*' || vis[nx][ny]) continue;

                if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z' && !key[board[nx][ny]-'A']) continue;

            }
        }
    }
}