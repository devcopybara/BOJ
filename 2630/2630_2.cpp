// https://www.acmicpc.net/problem/2630
#include <bits/stdc++.h>
using namespace std;

const int MX = 128; // 2^7
int board[MX][MX];
int ans[2];

int tmp[2][2];
int solve(int k, int r, int c) {
    if(k == 1) return board[r][c];

    bool is_all = true;


    int nk = k / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++) {
            tmp[i][j] = solve(nk,r + nk*i,c + nk*j);
            if(tmp[i][j] == 2) is_all = false;
        }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(tmp[0][0] != tmp[i][j]) is_all = false;

    if(is_all) return tmp[0][0];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            if(tmp[i][j] != 2) ans[tmp[i][j]]++;
    return 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int res = solve(n,0,0);
    if(res != 2) ans[res]++;
    cout << ans[0] << '\n' << ans[1];
}