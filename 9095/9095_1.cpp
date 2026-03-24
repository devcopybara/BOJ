// https://www.acmicpc.net/problem/9095

// f(n을 1,2,3의 합으로 나타내는 방법 총 가지수를 알기 위해 필요한 파라메터) = n을 1,2,3의 합으로 나타내는 방법 총 가지수
// f(n) = n을 1,2,3의 합으로 나타내는 방법 총 가지수

// f(0) = 0
// f(1) = 1 = (f(0) + 1)
// f(2) = 2 = f(1) + (f(0) + 1)
// f(3) = 4 = f(2) + f(2) + (f(0) + 1)
// ...
// f(k) = f(k-1) + f(k-2) + f(k-3)

#include <bits/stdc++.h>
using namespace std;

const int MX = 12;
int cnt[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        cnt[1] = 1;
        cnt[2] = 2;
        cnt[3] = 4;

        for(int i = 4; i <= n; i++) {
            cnt[i] = cnt[i-1] + cnt[i-2] + cnt[i-3];
        }

        cout << cnt[n] << '\n';
    }
}