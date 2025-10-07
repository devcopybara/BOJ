// https://www.acmicpc.net/problem/1256
#include <bits/stdc++.h>
using namespace std;
using uint16 = unsigned long long;
uint16 n, m, k;

uint16 comb[205][205];
char ans[205];
bool used[205];

void func(uint16 l, uint16 r) {
    if(r == 0) {
        for(uint16 i = 1; i <= n+m; i++)
            if(used[i])
                ans[n+m-i] = 'z';
        return;
    }

    uint16 cnt = 0;
    for(uint16 i = r; i <= l; i++) {
        cnt += comb[i-1][r-1];
        if(cnt >= k) {
            k -= (cnt - comb[i-1][r-1]);
            used[i] = 1;
            func(i - 1, r - 1);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    comb[0][0] = 1;
    for(uint16 i = 1; i <= 200; i++){
        comb[i][0] = comb[i][i] = 1;
        for(uint16 j = 1; j < i; j++) {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
            if (comb[i][j] > 1'000'000'000) comb[i][j] = 1'000'000'001;
        }
    }

    if(k > comb[n+m][m]) {
        cout << -1;
        return 0;
    }

    for(uint16 i = 0; i < n+m; i++) ans[i] = 'a';
    func(n+m, m);
    cout << ans;
}