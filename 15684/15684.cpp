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

void solve(int k, int mk) {
    if(k == mk) {
        if(check())
            ans = mk;
        return;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m-1; j++) {
            if(ans != -1) return;
            if(board[i][j-1] || board[i][j] || board[i][j+1]) continue;
            board[i][j] = 1;
            solve(k+1,mk);
            board[i][j] = 0;
        }
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

    ans = -1;
    for(int i = 0; i <= 3; i++) {
        solve(0,i);
        if(ans != -1) break;
    }
    cout << ans;
}