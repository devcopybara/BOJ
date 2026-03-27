// https://www.acmicpc.net/problem/1932
#include <bits/stdc++.h>
using namespace std;

const int MX = 502;
int score[MX][MX];
int d[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> score[i][j];

    for(int i = 1; i <= n; i++) d[i][1] += d[i-1][1]+score[i][1];
    for(int i = 2; i <= n; i++) d[i][i] += d[i-1][i-1]+score[i][i];
    
    for(int i = 3; i <= n; i++) {
        for(int j = 2; j < i; j++) {
            d[i][j] = max(d[i-1][j-1],d[i-1][j])+score[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans,d[n][i]);
    cout << ans;
}