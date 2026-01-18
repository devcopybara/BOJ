// https://www.acmicpc.net/problem/1781
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> hq;
vector<vector<int>> d2c(200'005);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d >> c;
        d2c[d].push_back(c);
    }

    int ans = 0;
    for (int d = 200'000; d > 0; d--) {
        for (int c : d2c[d]) hq.push(c);

        if (hq.empty()) continue;

        ans += hq.top(); hq.pop();
    }
    cout << ans;
}