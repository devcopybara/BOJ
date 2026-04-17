// https://www.acmicpc.net/problem/12865
#include <bits/stdc++.h>
using namespace std;

const int MXN = 102;
const int MXK = 100'002;

int w[MXN], v[MXN];
int d[MXN][MXK];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> w[i] >> v[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < w[i]; j++)
            d[i][j] = d[i-1][j];
        for(int j = w[i]; j <= k; j++)
            d[i][j] = max(d[i-1][j], d[i-1][j-w[i]]+v[i]);
    }

    cout << d[n][k];
}