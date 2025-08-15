#include <bits/stdc++.h>
using namespace std;
int n;
int board[6][20][20];
int ans;
int boardk[20][20];

void rotate(int b[20][20]) {
    int tmp[20][20];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[j][n-1-i] = b[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            b[i][j] = tmp[i][j];
}

void move(int k, int dir) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            boardk[i][j] = board[k][i][j];

    for(int r = 0; r < dir; r++)
        rotate(boardk);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board[k+1][i][j] = 0;

    for(int i = 0; i < n; i++) {
        int len = 0;
        for(int j = 0; j < n; j++)
            if(boardk[i][j])
                board[k+1][i][len++] = boardk[i][j];

        for(int j = 0; j < len-1; j++) {
            if(board[k+1][i][j] == board[k+1][i][j+1]) {
                board[k+1][i][j] *= 2;
                len--;
                for(int l = j+1; l < len; l++)
                    board[k+1][i][l] = board[k+1][i][l+1];
                board[k+1][i][len] = 0;
            }
        }
    }
}


void func(int k) {
    if(k == 5) {
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++)
                ans = max(ans, board[5][i][j]);
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        move(k, dir);
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[0][i][j];
    func(0);
    cout << ans;
}