// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>
using namespace std;

const uint64_t MX = 100'005;
uint64_t a[MX];
uint64_t aa[MX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n,s; cin >> n >> s;
    for(uint64_t i = 1; i <= n; i++) {
        cin >> a[i];
        aa[i] = aa[i-1] + a[i];
    }

    uint64_t ans = MX;

    for(uint64_t en = 0, st = 0; st < n; st++) {
        while(en <= n && aa[en]-aa[st] < s) en++;
        if(en == n+1) break;
        ans = min(ans, en-st);
    }
    cout << (ans == MX ? 0 : ans);
}