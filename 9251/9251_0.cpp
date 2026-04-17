// https://www.acmicpc.net/problem/9251

// 두 문자열의 LCS의 길이

// d[i][j] = (A[0~i], B[0~j]의 LCS 길이)
// d[i][j] = (A[i]==[j]) ? (d[i-1][j-1]+1) : max(d[i-1][j], d[i][j-1]);
// d[0][i] = 0, d[i][0] = 0;

#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
int d[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    if(a[0] == b[0]) d[0][0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == b[0]) d[i][0] = 1;
        else d[i][0] = d[i-1][0];
    }
    for(int j = 1; j < m; j++) {
        if(a[0] == b[j]) d[0][j] = 1;
        else d[0][j] = d[0][j-1];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(a[i] == b[j]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }

    cout << d[n-1][m-1];
}