#include <bits/stdc++.h>
using namespace std;

int ys[7][100];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int s, y;
    for(int i = 0; i < n; i++) {
        cin >> s >> y;
        ys[y][s]++;
    }

    int ans = 0;
    for(int i = 1; i <= 6; i++) {
        if(ys[i][0]) ans += (ys[i][0] + k - 1) / k;
        if(ys[i][1]) ans += (ys[i][1] + k - 1) / k;
    }
    cout << ans;
}