// https://www.acmicpc.net/problem/1790
// 1~9      9
// 10~99    90 * 2 = 180
// 100~999  900 * 3 = 2700
// ...
// 자리수 계산
#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    int len = 1, exp = 1;
    while (k > 9LL * len * exp) {
        k -= 9LL * len * exp;
        exp *= 10;
        len++;
    }
    int tar = exp + (k - 1) / len;
    if (tar > n) 
        cout << -1;
    else 
        cout << to_string(tar)[(k - 1) % len];
}