#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[9];

    for(int i = 0; i < 9; i++) cin >> a[i];

    cout << *max_element(a, a+9) << '\n';
    cout << max_element(a, a+9) - a + 1;
}