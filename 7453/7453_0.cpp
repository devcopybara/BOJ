#include <bits/stdc++.h>
using namespace std;
int n;
int a[4'005], b[4'005], c[4'005], d[4'005];
vector<int> ab;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ab.push_back(a[i]+b[j]);
    sort(ab.begin(),ab.end());

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += upper_bound(ab.begin(),ab.end(),-c[i]-d[j]) - lower_bound(ab.begin(),ab.end(),-c[i]-d[j]);
        }
    }
    cout << ans;
}