// https://www.acmicpc.net/problem/2630
#include <bits/stdc++.h>
using namespace std;

const int MX = 128; // 2^7
int board[MX][MX];
int ans[2];

bool is_all(int k, int r, int c) {
    for(int i = r; i < r + k; i++)
        for(int j = c; j < c + k; j++)
            if(board[r][c] != board[i][j]) 
                return false;
    return true;
}

void solve(int k, int r, int c) {
    if(k == 1) {
        ans[board[r][c]]++;
        return;
    }    
    
    if(is_all(k,r,c)) {
        ans[board[r][c]]++;
        return;
    }
    
    int nk = k / 2;
    for(int i = r; i < r + k; i += nk)
        for(int j = c; j < c + k; j += nk)
            solve(nk,i,j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    solve(n,0,0);
    cout << ans[0] << '\n' << ans[1];
}