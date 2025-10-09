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
    int64 en = 0, st = 0;
    while(en < n && st < n) {
        if(a[en]-a[st] < m) {
            en++;
        }
        else {
            ans = min(ans, a[en]-a[st]);
            st++;
        }
    }
    cout << ans;
}