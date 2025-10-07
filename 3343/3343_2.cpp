// https://www.acmicpc.net/problem/3343
// a 장미를 lst/a 이상 사는 경우는 c 장미를 통해서 더 싸게 구매할 수 있기 때문이다.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, c, d;
ll ans = LLONG_MAX;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

    cin >> n >> a >> b >> c >> d;

    if (a * d > b * c) {
        swap(a, c);
        swap(b, d);
    }

    ll lst = lcm(a, c);

    for (ll i = 0; i < (lst / a); i++) {
        ll cost = i * b;
        if (n - i * a > 0) cost += (((n - i * a - 1) / c) + 1) * d; // 1~c : 1묶음, c+1~2c : 2묶음, ...
        ans = min(ans, cost);
    }

    cout << ans;
}