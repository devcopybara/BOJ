#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int n;
int64 a[5'000];
int lower_idx(int st, int target) {
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(target <= a[mid]) en = mid;
        else st = mid+1;
    }
    return st;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a+n);
    int64 ans[3]={a[0],a[1],a[2]};
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int idx = lower_idx(j+1, -a[i]-a[j]);
            for(int k = -1; k <= 0; k++){
                if(idx+k == i || idx+k == j) continue;
                if(idx+k < 0 || idx+k >= n) continue;
                if(abs(ans[0] + ans[1] + ans[2]) > abs(a[i] + a[j] + a[idx+k]))
                    tie(ans[0], ans[1], ans[2]) = {a[i], a[j], a[idx+k]};     
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
}