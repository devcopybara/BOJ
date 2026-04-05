#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int64 t;
int64 n, m;
int64 a[1'005], b[1'005];
int64 aa[1'005], bb[1'005];
vector<int64> sa;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) aa[i] = aa[i-1]+a[i];
    for(int i = 1; i <= m; i++) bb[i] = bb[i-1]+b[i];

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            sa.push_back(aa[j]-aa[i-1]);
    sort(sa.begin(),sa.end());

    int64 ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            int64 target = t - (bb[j]-bb[i-1]);
            ans += upper_bound(sa.begin(),sa.end(),target) - lower_bound(sa.begin(),sa.end(),target);
        }
    }
    cout << ans;
}