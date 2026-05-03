// https://www.acmicpc.net/problem/2217

// 각 로프가 버틸 수 있는 최대 중량 a[i]
// k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량

// 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량?
// k개의 로프 최대 중량은 (k개 로프 중 최소 a[i]) * k
// k개의 로프 최대 중량을 최대로 하라면 (k개 로프 중 최소 a[i])를 최대로 해야한다.
// 즉, a[i]가 가장 큰 순서대로 k개 선택

// a[i]를 내림차순으로 정렬하여, k를 1씩 증가시키며 k에 따른 최대 중량 계산

#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a,a+n);

    int ans = 0;
    for(int k = 1; k <= n; k++) {
        ans = max(ans, a[n-k]*k);
    }
    cout << ans;
}