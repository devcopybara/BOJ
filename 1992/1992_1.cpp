// https://www.acmicpc.net/problem/1992
#include <bits/stdc++.h>
using namespace std;

// f(1) = f(2^0) : board[r][c]
// f(2^k)
// f(2^(k+1))
// : 주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"
// 전체를 한 번에 나타내지를 못하고, f(2^k) 4개의 영상으로 나누어 압축하게 되며, 
// 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현

const int MX = 64;
char board[MX][MX];
string ans;

bool is_all(int k, int r, int c) {
    for(int i = r; i < r+k; i++)
        for(int j = c; j < c+k; j++)
            if(board[i][j] != board[r][c])
                return false;
    return true;
}

void solve(int k, int r, int c) {
    if(is_all(k,r,c)) {
        ans += board[r][c];
        return;
    }

    ans += "(";
    int nk = k/2;
    for(int i = r; i < r+k; i+=nk)
        for(int j = c; j < c+k; j+=nk)
            solve(nk,i,j);
    ans += ")";
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
    cout << ans;
}