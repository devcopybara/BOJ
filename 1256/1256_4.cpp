#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1'000'000'001;
int comb[202][202];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    comb[0][0] = 1;
    for (int i = 1; i <= n + m; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
            if (comb[i][j] > INF) comb[i][j] = INF;
        }
    }

    if (k > comb[n+m][m]) {
        cout << -1;
        return 0;
    }

    string ans;
    ans.reserve(n + m);

    while (n && m) {
        if (k > comb[n + m - 1][m]) {
            k -= comb[n + m - 1][m];
            ans.push_back('z');
            m--;
        } else {
            ans.push_back('a');
            n--;
        }
    }

    ans.append(n, 'a');
    ans.append(m, 'z');

    cout << ans;
}
