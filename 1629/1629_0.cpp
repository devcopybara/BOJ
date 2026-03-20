// https://www.acmicpc.net/problem/1629
#include <bits/stdc++.h>
using namespace std;

uint64_t pow(int a, int b, int c) {
    uint64_t res = a % c;

    for(int i = 2; i <= b; i++) {
        res = res * res % c;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t a, b, c;
    cin >> a >> b >> c;
    cout << pow(a,b,c);
}