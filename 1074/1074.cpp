#include <bits/stdc++.h>
using namespace std;

int getorder(int n, int r, int c) {
    if(n == 0) return 0;

    int a = 1 << (n - 1);

    if(r >= a && c >= a) {
        return 3 * a * a + getorder(n - 1, r - a, c - a);
    }
    else if(r >= a) {
        return 2 * a * a + getorder(n - 1, r - a, c);
    }
    else if(c >= a) {
        return a * a + getorder(n - 1, r, c - a);
    }
    else {
        return getorder(n - 1, r, c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;

    cout << getorder(n, r, c);
}