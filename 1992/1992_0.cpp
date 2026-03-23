#include <bits/stdc++.h>
using namespace std;

const int MX = 64;
char papper[MX][MX];
int ans[2];

void cutting(int n, int r, int c) {
    if(n == 1) {
        cout << papper[r][c]; // ans[papper[r][c]]++;
        return;
    }

    for(int i = r; i < r + n; i++) {
        for(int j = c; j < c + n; j++) {
            if(papper[i][j] != papper[r][c]) {
                // 4등분
                cout << "(";
                int m = n / 2;
                for(int x = 0; x < n; x += m) {
                    for(int y = 0; y < n; y += m) {
                        cutting(m, r + x, c + y);
                    }
                }
                cout << ")";
                return;
            }
        }
    }
    cout << papper[r][c]; // ans[papper[r][c]]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> papper[i][j];
        }
    }

    cutting(n, 0, 0);
    // cout << ans[0] << '\n' << ans[1];
}