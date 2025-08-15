#include <bits/stdc++.h>
using namespace std;

int n;
int d[300];
int w[300];
int ans;
int cnt;

void func(int k) {
    if(k == n) {
        ans = max(ans, cnt);
        return;
    }

    if(d[k] <= 0 or cnt == n - 1) {
        func(k + 1);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(i == k or d[i] <= 0) continue;
        d[k] -= w[i];
        d[i] -= w[k];
        cnt += (d[k] <= 0) + (d[i] <= 0);
        func(k + 1);
        cnt -= (d[k] <= 0) + (d[i] <= 0);
        d[k] += w[i];
        d[i] += w[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> d[i] >> w[i];
    func(0);
    cout << ans;
}