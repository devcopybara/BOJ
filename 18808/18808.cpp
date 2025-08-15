#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool board[40][40];
int r, c;
bool sticker[10][10];
bool sticker2[10][10];

bool isOverlap(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[x + i][y + j] && sticker[i][j]) {
                return true;
            }
        }
    }

    return false;
}

void attach(int x, int y) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(sticker[i][j]) {
                board[x + i][y + j] = 1;
            }
        }
    }
}

void rotate() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sticker2[j][r-1-i] = sticker[i][j];
        }
    }
    swap(r,c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sticker[i][j] = sticker2[i][j];
        }
    }
}

bool check() {
    for(int i = 0; i < n - r + 1; i++) {
        for(int j = 0; j < m - c + 1; j++) {
            if(!isOverlap(i,j)) {
                attach(i,j);
                return true;
            }
        }
    }
    rotate();
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }

        for(int dir = 0; dir < 4; dir++) {
            if(check()) {
                break;
            }
        }

    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j]) {
                ans++;
            }
        }
    }
    cout << ans;
}