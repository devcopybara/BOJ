#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[27][27];
bool vis[27][27];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
queue<pair<int,int>> Q;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<int> ans;
    int size = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == '0' || vis[i][j]) continue;
            size++;
            int cnt = 1;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(board[nx][ny] == '0' || vis[nx][ny]) continue;
                    cnt++;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout << size << '\n';
    for(int i : ans) cout << i << '\n';
}