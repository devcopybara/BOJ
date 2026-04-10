// https://www.acmicpc.net/problem/20366

// 두 눈사람의 키의 차이 최소값

#include <bits/stdc++.h>
using namespace std;

const int64_t MX = 605;
int64_t a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n; cin >> n;
    for(int64_t i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);

    int64_t ans = 1e9;
    for(int64_t i = n-1; i >= 0; i--) {
        for(int64_t j = i-1; j >= 0; j--) {
            int64_t hi = a[i]+a[j];
            
            int64_t st = 0;
            for(int64_t en = n-1; en > 0; en--) {
                if(en == i || en == j) continue;

                while(st < en && hi >= a[st]+a[en]) {
                    if(st != j && st != i) ans = min(ans, hi-a[st]-a[en]);
                    st++;
                }

                if(st == en) break;
            }
        }
    }
    cout << ans;
}