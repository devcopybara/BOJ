// https://www.acmicpc.net/problem/14502
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n, m;
int board[8][8];
vector<pair<int,int>> virus;
vector<pair<int,int>> blink;
int ans;

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int safetyzone() {
    bool vis[8][8];
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + m, 0);

    queue<pair<int,int>> q;
    for(auto v : virus) {
        vis[v.X][v.Y] = 1;
        q.push(v);
    }
    while(!q.empty()) {
        auto curr = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = curr.X + dx[dir];
            int ny = curr.Y + dy[dir];
            if(OOB(nx,ny) || board[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }

    int tot = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 0 && !vis[i][j])
                tot++;
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == 0) {
                blink.push_back({i,j});
            }
            else if(tmp == 2) {
                virus.push_back({i,j});
            }
        }
    }

    int size = blink.size();
    vector<int> brute(size);
    fill(brute.begin() + size - 3, brute.end(), 1);
    do{
        for(int i = 0; i < size; i++)
            if(brute[i] == 1) 
                board[blink[i].X][blink[i].Y] = 1;

        ans = max(ans, safetyzone());
        
        for(int i = 0; i < size; i++)
            if(brute[i] == 1) 
                board[blink[i].X][blink[i].Y] = 0;
    }while(next_permutation(brute.begin(), brute.end()));

    cout << ans;
}