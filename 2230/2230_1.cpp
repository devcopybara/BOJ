// https://www.acmicpc.net/problem/2230
#include <bits/stdc++.h>
using namespace std;

const int INF= 2'000'000'000;
const int MX = 100'005;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a,a+n);

    int ans = INF;
    for(int i = 0; i < n; i++) {
        int k = lower_bound(a+i+1,a+n,a[i]+m) - a;
        if(k == n) continue;
        ans = min(ans,a[k]-a[i]);
    }
    cout << ans;
}