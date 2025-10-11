#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 n, m;
int64 a[100'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int64 i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);

    int64 ans = LONG_LONG_MAX;
    for(int64 i = 0; i < n; i++) {
        int64 idx = lower_bound(a,a+n,a[i]+m) - a;
        if(idx != n)
            ans = min(ans, abs(a[i]-a[idx]));
    }
    cout << ans;
}