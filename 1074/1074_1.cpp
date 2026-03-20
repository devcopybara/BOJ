// https://www.acmicpc.net/problem/1074

// f(1,r,c) = 1 * [0,1,2,3]
// f(k,r,c) : 2^k * 2^k 배열의 Z모양 탐색 (r,c)의 방문 순서
// f(k+1,r,c) = 2^k * 2^k * [0,1,2,3] + f(k,r',c')

#include <bits/stdc++.h>
using namespace std;

uint64_t get_order(uint64_t k, uint64_t r, uint64_t c) {
    if(k == 0) return 0;

    uint64_t h = 1 << (k-1);
    uint64_t a = h * h;
    if(r < h && c < h) return get_order(k-1, r, c);
    else if(r < h && c < h * 2) return a + get_order(k-1, r, c-h);
    else if(r < h * 2 && c < h) return 2 * a + get_order(k-1, r-h, c);
    else return 3 * a + get_order(k-1, r-h, c-h);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t n, r, c;
    cin >> n >> r >> c;
    cout << get_order(n,r,c);
}