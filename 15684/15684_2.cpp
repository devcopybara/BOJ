// https://www.acmicpc.net/problem/15684
#include <bits/stdc++.h>
using namespace std;

int n, m, l;
int board[32][12];
int ans;

bool check() {
    for(int k = 1; k <= m; k++) {
        int j = k;
        for(int i = 1; i <= n; i++) {
            if(board[i][j]) 
                j++;
            else if(board[i][j-1])
                j--;
        }
        if(j != k)
            return false;
    }
    return true;
}

void solve(int si, int sj, int k, int mk) {
    if(check())
        ans = k;
        
    if(k == mk || k >= ans) {
        return;
    }

    for(int i = si; i <= n; i++) {
        for(int j = sj; j <= m-1; j++) {
            if(k >= ans) return;
            if(board[i][j-1] || board[i][j] || board[i][j+1]) continue;
            board[i][j] = 1;
            solve(i,j,k+1,mk);
            board[i][j] = 0;
        }
        sj = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> l >> n;
    while(l--) {
        int a, b;
        cin >> a >> b; 
        board[a][b] = 1;
    }

    ans = 4;
    solve(0,0,0,3);
    cout << (ans == 4 ? -1 : ans);
}