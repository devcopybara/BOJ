// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>
using namespace std;

const uint64_t MX = 100'005;
uint64_t a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n,s; cin >> n >> s;
    for(uint64_t i = 1; i <= n; i++) cin >> a[i];

    uint64_t ans = MX;

    uint64_t sum = 0;
    for(uint64_t en = 1, st = 1; st <= n; st++) {
        while(en <= n && sum < s) {
            sum += a[en];
            en++;
        }
        if(sum < s) break;
        ans = min(ans, en-st);

        sum -= a[st];
    }

    cout << (ans == MX ? 0 : ans);
}