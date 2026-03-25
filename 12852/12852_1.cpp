// https://www.acmicpc.net/problem/12852

// f(1) = 0
// f(k) = min(f(k/3)+1,f(k/2)+1,f(k-1)+1)
// ...
// f(n) = ?

#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6+1;
int cnt[MX];
int pre[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cnt[1] = 0;
    for(int i = 2; i <= n; i++) {
        cnt[i] = cnt[i-1]+1; pre[i] = i-1;

        if(i % 2 == 0) {
            if(cnt[i] > cnt[i/2]+1) {
                cnt[i] = cnt[i/2]+1; pre[i] = i/2;
            }
        }
        
        if(i % 3 == 0) {
            if(cnt[i] > cnt[i/3]+1) {
                cnt[i] = cnt[i/3]+1; pre[i] = i/3;
            }
        }
    }

    cout << cnt[n] << '\n';
    int cur = n;
    while(cur > 0) {
        cout << cur << ' ';
        cur = pre[cur];
    }
}