#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {1,1,1,0,-1,-1,-1,0};
int n, m, k;
char board[10][10];
unordered_map<string,int> cnt;

void func(int x, int y, int k, string s) {
    cnt[s]++;
    if(k == 5) return;
    for(int dir = 0; dir < 8; dir++) {
        int nx = (n+x+dx[dir])%n;
        int ny = (m+y+dy[dir])%m;
        func(nx, ny, k+1, s+board[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            func(i,j,1,string(1,board[i][j]));
    while(k--) {
        string s;
        cin >> s;
        cout << cnt[s] << '\n';
    }
}