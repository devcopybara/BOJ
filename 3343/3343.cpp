// https://www.acmicpc.net/problem/3343
// ax + cy >= n -> min(bx + dy)?
// 0 <= x <= (n + a - 1) / a
// 0 <= y <= (n + c - 1) / c
#include <bits/stdc++.h>
using namespace std;
typedef long long int16;
int16 n, a, b, c, d;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b >> c >> d;
    if((double)b/a < (double)d/c) {
        swap(a,c);
        swap(b,d);
    }

    int16 ans = b * (n + a - 1) / a + d * (n + c - 1) / c;
    for(int16 y = (n + c - 1) / c; y >= 0; y--) {
        for(int16 x = 0; x <= (n + a - 1) / a; x++) {
            if(a * x + c * y >= n) {
                ans = min(ans, b * x + d * y);
                break;
            }
        }
    }
    cout << ans;
}