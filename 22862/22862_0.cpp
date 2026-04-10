#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1'000'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int cnt = (a[0] & 1 == 1) ? 1 : 0;
    int en = 0;
    for(int st = 0; st < n; st++){
        while(en < n-1 && cnt + a[en+1] & 1 <= k){
            en++;
            cnt += a[en] & 1;
        }
        ans = max(ans, en - st + 1 - cnt);

        if(a[st] & 1) cnt--;
    }
    cout << ans;
}