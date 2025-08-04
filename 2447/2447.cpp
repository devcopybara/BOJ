#include <bits/stdc++.h>
using namespace std;

const int MX = 6600;
char star[MX][MX];

void draw(int n, int r, int c) {
    if(n == 1) {
        star[r][c] = '*';
        return;
    }

    // 9등분
    int m = n / 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            draw(m, r + m * i, c + m * j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) fill(star[i], star[i] + n, ' ');
    draw(n, 0, 0);
    for(int i = 0; i < n; i++) cout << star[i] << '\n';
}