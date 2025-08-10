#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
pair<int,int> xy[25];
char board[5][5];
int arr[7];
int ans;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool check() {
    int cnt = 0;
    for(int i = 0; i < 7; i++) {
        if(board[xy[arr[i]].X][xy[arr[i]].Y] == 'S')
            cnt++;
    }
    if(cnt < 4) 
        return false;

    int vis[5][5] = {0,};
    int pos[5][5] = {0,};
    for(int i = 0; i < 7; i++)
        pos[xy[arr[i]].X][xy[arr[i]].Y] = 1;
    queue<pair<int,int>> Q;
    Q.push(xy[arr[0]]);
    vis[xy[arr[0]].X][xy[arr[0]].Y] = 1;
    cnt = 0;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        cnt++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(vis[nx][ny] || !pos[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    if(cnt == 7) 
        return true;
        
    return false;
}
void func(int k) {
    if(k == 7) {
        if(check())
            ans++;
        return;
    }
    int s = k == 0 ? 0 : arr[k - 1] + 1;
    for(int i = s; i < 25; i++) {
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 25; i++) 
        xy[i] = { i / 5, i % 5 };

    for(int i = 0; i < 5; i++)
        cin >> board[i];

    func(0);
    cout << ans;
}