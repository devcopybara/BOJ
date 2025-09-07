#include <bits/stdc++.h>
using namespace std;

int n, l;
int board[2][100][100];

int check(int board[100][100]) {
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        int j = 0;
        int len = 1;
        while(j + 1 < n) {
            if(board[i][j] == board[i][j+1]) {
                len++;
            }                
            else if(board[i][j+1] == board[i][j] + 1) {
                if(len < l) break;
                len = 1;
            }
            else if(board[i][j+1] == board[i][j] - 1) {
                len = 1;
                while(len < l && j + 2 < n) {
                    if(board[i][j+1] != board[i][j+2])
                        break;
                    j++;
                    len++;
                }
                if(len < l) break;
                len = 0;
            }
            else {
                break;
            }

            j++;
        }

        if(j == n - 1) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[0][i][j];
            board[1][j][n-1-i] = board[0][i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        ans += check(board[i]);
    }
    cout << ans;
}