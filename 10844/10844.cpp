// https://www.acmicpc.net/problem/10844
#include <bits/stdc++.h>
using namespace std;

// f(1) = 9 : [1,2,..,9]
// f(2) = 17 : [1,2,..,9]->[0,1,..,8] + [1,2,..,9]->[2,3,..,0] = 9 + 9 - 1 
// f(3) = ...

const int MX = 102;
const int DIV= 1'000'000'000;
int cnt[MX][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++) cnt[1][i] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 10; j++) {
            if(j > 0) cnt[i][j] += cnt[i-1][j-1];
            if(j < 9) cnt[i][j] += cnt[i-1][j+1];
            cnt[i][j] %= DIV;
        }
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++) ans = (ans + cnt[n][i]) % DIV;
    cout << ans;
}