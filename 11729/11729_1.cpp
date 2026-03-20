// https://www.acmicpc.net/problem/11729

// f(1) = 1
// f(k+1) = f(k) + 1 + f(k)

// f(1) = [1]a->c : a c
// f(k) = [k]a->c : ???
// f(k+1) = [k+1]a->c = [k]a->b + [1]a->c + [k]b->c

#include <bits/stdc++.h>
using namespace std;

int hanoi(int k) {
    if(k == 1) return 1;
    return hanoi(k-1) * 2 + 1;
}

void trace_hanoi_process(int k, int a, int b, int c) { // k a->b->c
    if(k == 0) return;

    trace_hanoi_process(k-1, a, c, b); // k-1 a->c->b
    cout << a << ' ' << c << '\n';     // 1 a->c
    trace_hanoi_process(k-1, b, a, c); // k-1 b->a->c
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << hanoi(n) << '\n';
    trace_hanoi_process(n, 1, 2, 3);
}