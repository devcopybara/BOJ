// https://www.acmicpc.net/problem/1744

// 0. 문제
// 수열의 각 수를 적절히 묶었을 때, 그 합이 최대

// 1. 정의
// 수열의 두 수를 묶어서 곱할 수 있을 때 최대합?

// 2. 풀이
// 큰 양수들끼리 곱한다.
// 작은 음수들끼리 곱한다.
// 음수가 하나 남으면 0이랑 곱한다.
// 1은 더한다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a,a+n);

    int ans = 0;

    int i = 0;
    while(i < n) {
        if((i == n-1) || (a[i] == 0) || (a[i] == 1) || (a[i] * a[i+1] < 0) || (a[i] > 0 && (n-i) % 2 == 1)) {
            ans += a[i];
            i++;
        }
        else {
            ans += a[i] * a[i+1];
            i+=2;
        }
    }

    cout << ans;
}