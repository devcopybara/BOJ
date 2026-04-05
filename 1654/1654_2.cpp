// https://www.acmicpc.net/problem/1654
#include <bits/stdc++.h>
using namespace std;

const uint64_t MX = 10'005;
uint64_t a[MX];
uint64_t k, n;

uint64_t get_cnt(uint64_t len) {
    uint64_t cnt = 0;

    for(uint64_t i = 0; i < k; i++) cnt += a[i]/len;

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(uint64_t i = 0; i < k; i++) cin >> a[i];

    uint64_t st = 1;
    uint64_t en = 0x7fffffff;

    while(st < en) {
        uint64_t mid = (st+en+1)/2;
        uint64_t cnt = get_cnt(mid);

        if(cnt < n) {
            en = mid-1;
        }
        else if(cnt > n) {
            st = mid;
        }
        else {
            st = mid;
        }
    }
    
    cout << en;
}