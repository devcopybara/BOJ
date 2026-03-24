// https://www.acmicpc.net/problem/1463

// f(1) = 0
// f(k) = min(f(k/3)+1,f(k/2)+1,f(k-1)+1)
// ...
// f(n) = ?

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6+1;
int cnt[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cnt[1] = 0;
    for(int i = 2; i <= n; i++) {
        cnt[i] = cnt[i-1]+1;
        if(i % 2 == 0) cnt[i] = min(cnt[i],cnt[i/2]+1);
        if(i % 3 == 0) cnt[i] = min(cnt[i],cnt[i/3]+1);
    }
    cout << cnt[n];
}