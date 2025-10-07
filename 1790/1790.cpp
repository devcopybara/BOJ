// https://www.acmicpc.net/problem/1790
#include <bits/stdc++.h>
using namespace std;
int n, k;
int digit(int n) {
    int d = 0;
    while(n) {
        n /= 10;
        d++;
    }
    return d;
}
int get_digit_num(int i, int d) {
    while(d--) {
        i /= 10;
    }
    return i % 10;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;


    for(int i = 1; i <= n; i++) {
        k -= digit(i);
        if(k <= 0) {
            cout << get_digit_num(i, -k);
            return 0;
        }
    }
    cout << -1;
}