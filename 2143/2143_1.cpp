// https://www.acmicpc.net/problem/2143
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
int a[MX],b[MX];
int aa[MX], bb[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        aa[i] = aa[i-1]+a[i];
    }
    int m; cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        bb[i] = bb[i-1]+b[i];
    }

    vector<int> sa;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            sa.push_back(aa[j]-aa[i]);
        }
    }

    vector<int> sb;
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j <= m; j++) {
            sb.push_back(bb[j]-bb[i]);
        }
    }
    sort(sb.begin(),sb.end());

    int64_t ans = 0;
    for(int x : sa) {
        int st = lower_bound(sb.begin(),sb.end(),t-x)-sb.begin();
        int en = upper_bound(sb.begin(),sb.end(),t-x)-sb.begin();
        ans += en-st;
    }
    cout << ans;
}