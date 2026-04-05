// https://www.acmicpc.net/problem/2302
#include <bits/stdc++.h>
using namespace std;

// f(n) : 좌석의 개수가 n개일 때, 사람들이 좌석에 앉을 수 있는 방법의 가짓수
// f(0) = 1
// f(1) = 1
// f(2) = 2 = 1 + 1 = f(1) + f(0)
// f(3) = 3 = 1 + 1 + 1 = f(2) + f(1)
// f(4) = 5 = 1 + 1 + 1 + 1 + 1 = f(3) + f(2)
// ...
// f(k) = f(k-1) + f(k-2) (k-3개 경우 부터는 중복)

const int MX = 42;
int pibo[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pibo[0] = pibo[1] = 1;
    for(int i = 2; i <= n; i++) pibo[i] = pibo[i-1] + pibo[i-2];

    int ans = 1;
    int pre = 0;
    for(int i = 0; i < m; i++) {
        int cur;
        cin >> cur;

        ans *= pibo[cur-pre-1];

        pre = cur;
    }
    ans *= pibo[n+1-pre-1];
    cout << ans;
}