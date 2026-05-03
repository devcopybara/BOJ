// https://www.acmicpc.net/problem/1744

// 0. 문제
// 수열의 각 수를 적절히 묶었을 때, 그 합이 최대

// 1. 정의
// 수열의 두 수를 묶어서 곱할 수 있을 때 최대합?

// 2. 풀이
// 1은 더한다.
// 큰 양수들끼리 곱한다.
// 남은 양수는 더한다.
// 작은 음수들끼리 곱한다.
// 음수가 하나 남으면 0이랑 곱한다.
// 남은 음수는 더한다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int ans = 0;

    int m = 0;
    while(n--) {
        int tmp;
        cin >> tmp;
        
        if(tmp == 1) ans++;
        else a[m++] = tmp;
    }
    sort(a,a+m);

    int i = m-1;
    while(i >= 1 && a[i] > 0 && a[i-1] > 0) {
        ans += a[i] * a[i-1];
        i-=2;
    }
    if(a[i] > 0) ans += a[i];

    i = 0;
    while(i <= m-2 && a[i] < 0 && a[i+1] <= 0) {
        ans += a[i] * a[i+1];
        i+=2;
    }
    if(a[i] < 0) ans += a[i];

    cout << ans;
}