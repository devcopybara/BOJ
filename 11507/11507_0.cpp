// https://www.acmicpc.net/problem/11057
#include <bits/stdc++.h>
using namespace std;

// d[1] =  1+1+1+..+1 = 10
// d[2] = 10+9+8+..+1 = 55

// d[2] = d[1][0]*10 + d[1][1]*9 + ... + d[1][9]*1

const int MX = 1'005;
const int DIV= 10'007;

int d[MX][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i <= 9; i++)
        d[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = j; k <= 9; k++) {
                d[i][k] = (d[i][k]+d[i-1][j])%DIV;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++)
        ans = (ans+d[n][i])%DIV;
    cout << ans;
}