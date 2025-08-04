#include <bits/stdc++.h>
using namespace std;

int64_t abmodc(int64_t a, int64_t b, int64_t c) {
    if(b == 1) return a % c;
    int64_t val = abmodc(a, b / 2, c);
    val = val * val % c;
    if(b & 1) return a * val % c;
    else return val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << abmodc(a, b, c);
}