// https://www.acmicpc.net/problem/13975
#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;

        priority_queue<uint64, vector<uint64>, greater<uint64>> pq;
        for(int i = 0; i < k; i++) {
            uint64 x;
            cin >> x;
            pq.push(x);
        }

        uint64 ans = 0;
        while(pq.size() > 1) {
            uint64 a = pq.top(); pq.pop();
            uint64 b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a+b);
        }
        cout << ans << '\n';
    }
}