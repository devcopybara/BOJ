// https://www.acmicpc.net/problem/1780

// cnt[3] = [-1, 0, 1]
// f(1) = f(3^0) = cnt[board[r][c] + 1]++
// f(3^k)
// f(3^(k+1)) = (1) 모두 같으면 cnt[val+1]++ (2) 아닌 경우 9조각으로 자르고 9번의 f(3^k)

#include <bits/stdc++.h>
using namespace std;

const int MX = 2200; // 2187
int board[MX][MX];
int cnt[3];

bool is_all(int k, int r, int c) {
    int val = board[r][c];
    for(int i = r; i < r + k; i++) {
        for(int j = c; j < c + k; j++) {
            if(val != board[i][j]) return false;
        }
    }
    return true;
}

void paper_cut(int k, int r, int c) {
    if(k == 1) {
        cnt[board[r][c]+1]++;
        return;
    }

    if(is_all(k,r,c)) {
        cnt[board[r][c]+1]++;
        return;
    }

    int nk = k / 3;
    for(int i = r; i < r + k; i += nk) {
        for(int j = c; j < c + k; j += nk) {
            paper_cut(nk,i,j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    paper_cut(n,0,0);
    for(int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}