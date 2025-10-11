// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;
int n; 
uint64 s;
uint64 a[100'005];
uint64 sa[100'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) sa[i] = sa[i-1]+a[i];

    int ans = INT_MAX;
    int en = 1;
    for(int st = 1; st <= n; st++) {
        while(en<=n && sa[en]-sa[st-1]<s) en++;
        if(en>n) break;
        ans = min(ans, en-st+1);
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans;
}