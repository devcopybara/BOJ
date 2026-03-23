// https://www.acmicpc.net/problem/1780
#include <bits/stdc++.h>
using namespace std;

const int MX = 2187;
int papper[MX][MX];

int ans[3];
void cutting(int n, int r, int c) {
    if(n == 1) {
        ans[papper[r][c] + 1]++;
        return;
    }

    for(int i = r; i < r + n; i++) {
        for(int j = c; j < c + n; j++) {
            if(papper[i][j] != papper[r][c]) {
                // 9등분
                int m = n / 3;
                for(int x = 0; x < n; x += m) {
                    for(int y = 0; y < n; y += m) {
                        cutting(m, r + x, c + y);
                    }
                }
                return;
            }
        }
    }
    ans[papper[r][c] + 1]++;
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
    
    for(int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }
}