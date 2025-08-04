#include <bits/stdc++.h>
using namespace std;

const int MX = 3100;
char star[MX][MX * 2];

void draw_triangle(int r, int c) {
    star[r][c + 2] = '*';
    star[r + 1][c + 1] = star[r + 1][c + 3] = '*';
    for(int i = 0; i < 5; i++) star[r + 2][c + i] = '*';
}

void draw(int n, int r, int c) {
    if(n == 3) {
        draw_triangle(r, c);
        return;
    }

    int m = n / 2;
    draw(m, r, c + m);
    draw(m, r + m, c);
    draw(m, r + m, c + n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) fill(star[i], star[i] + 2 * n - 1, ' ');
    draw(n, 0, 0);
    for(int i = 0; i < n; i++) cout << star[i] << '\n';
}