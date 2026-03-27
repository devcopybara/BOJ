// https://www.acmicpc.net/problem/11726
#include <bits/stdc++.h>
using namespace std;

// f(1) = 1
// f(2) = 2
// f(3) = f(1) + f(2)

const uint64_t MX = 1'002;
uint64_t cnt[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n;
    cin >> n;

    cnt[1] = 1;
    cnt[2] = 2;
    for(uint64_t i = 3; i <= n; i++) {
        cnt[i] = (cnt[i-1] + cnt[i-2]) % 10'007;
    }

    cout << cnt[n];
}