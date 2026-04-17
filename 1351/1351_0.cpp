// https://www.acmicpc.net/problem/1351
#include <bits/stdc++.h>
using namespace std;

// const uint64_t MX = 1'000'000'000'005;
unordered_map<uint64_t,uint64_t> d;

uint64_t p,q;
uint64_t getA(uint64_t n) {
    if(d.find(n) != d.end()) return d[n];

    d[n] = getA(n/p)+getA(n/q);
    return d[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 1;
    uint64_t n; cin >> n >> p >> q;

    cout << getA(n);
}