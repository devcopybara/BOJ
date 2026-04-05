// https://www.acmicpc.net/problem/11052
#include <bits/stdc++.h>
using namespace std;

// d[n] = N개를 갖기 위해 지불해야 하는 금액의 최댓값 = N개 최대값
// d[n] = max(p[n], d[n-1]+d[1], d[n-2]+d[2], ...)

// d[1] = p[1]
// d[2] = max(p[2], d[1]+d[1])
// d[3] = max(p[3], d[2]+d[1])
// .. 
// d[k] = max(p[k], d[k-1]+d[1], d[k-2]+d[2], ...)

const int MX = 1'005;
int p[MX];
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    
    d[1] = p[1];
    for(int i = 2; i <= n; i++) {
        d[i] = p[i];
        int h = i/2;
        for(int j = 1; j <= h; j++) {
            d[i] = max(d[i],d[j]+d[i-j]);
        }
    }
    cout << d[n];
}