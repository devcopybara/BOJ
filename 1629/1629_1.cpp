// https://www.acmicpc.net/problem/1629

// f(1) = a % c
// f(2k) = f(k) * f(k) % c
// f(2k+1) = f(2k) * a % c

#include <bits/stdc++.h>
using namespace std;

uint64_t pow(int a, int b, int c) {
    if(b == 1) return a % c;

    uint64_t res = pow(a, b/2, c);
    res = res * res % c;

    return (b & 1) ? res * a % c : res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t a, b, c;
    cin >> a >> b >> c;
    cout << pow(a,b,c);
}