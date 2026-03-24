#include <bits/stdc++.h>
using namespace std;

int t, n;
int d[12];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    while(t--) {
        cin >> n;
        for(int i = 3; i <= n; i++)
            d[i] = d[i-3]+d[i-2]+d[i-1];
        cout << d[n] << '\n';
    }
}