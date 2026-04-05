// https://www.acmicpc.net/problem/7453
#include <bits/stdc++.h>
using namespace std;

const int64_t MX = 4'005;
int64_t a[MX], b[MX], c[MX], d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n; cin >> n;
    for(int64_t i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int64_t> ab;
    for(int64_t i = 0; i < n; i++)
        for(int64_t j = 0; j < n; j++)
            ab.push_back(a[i]+b[j]);

    vector<int64_t> cd;
    for(int64_t i = 0; i < n; i++)
        for(int64_t j = 0; j < n; j++)
            cd.push_back(c[i]+d[j]);

    sort(cd.begin(),cd.end());
    int cd_sz = cd.size();

    int64_t ans = 0;
    for(int64_t x : ab) {
        int64_t st = lower_bound(cd.begin(),cd.end(),-x)-cd.begin();
        if(st == cd_sz) continue;
        int64_t en = upper_bound(cd.begin(),cd.end(),-x)-cd.begin();
        ans += en-st;
    }
    cout << ans;
}