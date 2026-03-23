// https://www.acmicpc.net/problem/1780

// cnt[3] = [-1, 0, 1]
// f(1) = f(3^0) = cnt[r][c][board[r][c] + 1]++
// f(3^k)
// f(3^(k+1)) = (1) 9조각으로 자르고 9번의 f(3^k) (2) 9조각이 모두 같으면 cnt[r][c][val+1], 아니면 9조각 cnt[r][c][val+1] 종합

#include <bits/stdc++.h>
using namespace std;

const int MX = 2200; // 2187
int board[MX][MX];
int cnt[MX][MX][4];

int paper_cut(int k, int r, int c) {
    if(k == 1) {
        cnt[r][c][board[r][c]+1]++;
        return 1;
    }
    
    bool is_all = true;
    int tot = 0;
    int _cnt[3] = {0,0,0};

    int nk = k / 3;
    for(int i = r; i < r + k; i += nk) {
        for(int j = c; j < c + k; j += nk) {
            int tmp = paper_cut(nk,i,j);
            tot += tmp;
            if(tmp != 1) is_all = false;
            
            for(int k = 0; k < 3; k++) {
                _cnt[k] += cnt[i][j][k];
                if(cnt[r][c][k] != cnt[i][j][k]) is_all = false;
            }
        }
    }

    if(is_all == false) {
        for(int i = 0; i < 3; i++) cnt[r][c][i] = _cnt[i];
        return tot;
    }
    return 1;
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
    for(int i = 0; i < 3; i++) cout << cnt[0][0][i] << '\n';
}