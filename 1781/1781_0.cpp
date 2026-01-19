// https://www.acmicpc.net/problem/1781

// 0. 문제
// n개의 각 문제의 데드라인 d_i 시간과 문제를 풀었을 때 받을 수 있는 컵라면 수 c_i가 있고, 한 문제를 풀기 위해 1시간이 걸릴 때, 받을 수 있는 최대 컵라면 수를 구하라

// 1. 재정의
// 1시간에 1문제를 풀 수 있고, 각 데드라인 d_i와 컵라면 c_i인 문제 n개가 있을 때, 받을 수 있는 최대 컵라면 수를 구하라

// 2. 풀이
// 제약 조건이 큰 데드라인 200'000부터 시작해서, 데드라인이 넘지 않는 문제들 중 가장 컵라면이 많은 문제를 푼다.
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