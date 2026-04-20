// https://www.acmicpc.net/problem/11047

// a[i] 동전은 a[i-1] 동전의 배수, 필요한 동전 개수의 최솟값

// 1. 가설
// 모든 동전이 배수 관계이므로, a[i] 동전은 a[i-1] 동전으로 대체할 수 있다.
// 반대로 a[i-1] 동전이 일정량 이상이면 a[i]로 부분 대체할 수 있다.
// a[i-1] 동전을 a[i] 동전으로 대체할 수 있으면 대체하는게 이득이다.

// 2. 증명 - 귀류법
// a[i-1] 이 c개 이상 있을 때, a[i] 로 대체하지 않는 것이 최솟값이라고 가정한다. (a[i] = c * a[i-1])
// a[i-1] 이 c개를 a[i]로 대체하면 c-1개가 감소한다.
// 그러므로 가정은 거짓이므로 가설은 참이다.

#include <bits/stdc++.h>
using namespace std;

const int MX = 10;
int a[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        ans += k / a[i];
        k %= a[i];
    }
    cout << ans;
}