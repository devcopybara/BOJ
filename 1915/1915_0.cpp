// https://www.acmicpc.net/problem/1915

// d[i][j] = (i,j)를 끝점으로 만들 수 있는 정사각형 최대 크기

#include <bits/stdc++.h>
using namespace std;

const int MX = 1'004;
char board[MX][MX];
int d[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> board[i][j];

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == '0') continue;

            d[i][j] = min(d[i][j-1],d[i-1][j]);
            if(board[i-d[i][j]][j-d[i][j]] == '1') d[i][j] += 1;

            ans = max(ans, d[i][j]);
        }
    }

    cout << ans * ans;
}