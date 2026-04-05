// https://www.acmicpc.net/problem/9465
#include <bits/stdc++.h>
using namespace std;

// d[n] = 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값 = 2n개 최댓값
// d[n] = max(d[n][0],d[n][1],...)

// 2n개 최대값을 구하기 위해 필요한 스티커 조합
// (a/b) : a = 1행 스티커, b = 2행 스티커

// (x/x) [0]
// (x/o) [1]
// (o/x) [2]

// d[k][0] = max(d[k-1][0],d[k-1][1],d[k-1][2])
// d[k][1] = max(d[k-1][0],d[k-1][2])
// d[k][2] = max(d[k-1][0],d[k-1][1])

const int MX = 100'005;
int a[3][MX];
int d[MX][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= n; j++)
                cin >> a[i][j];
        
        d[1][1] = a[1][1];
        d[1][2] = a[2][1];

        for(int i = 2; i <= n; i++) {
            d[i][0] = max(max(d[i-1][0],d[i-1][1]),d[i-1][2]);
            d[i][1] = max(d[i-1][0],d[i-1][2])+a[1][i];
            d[i][2] = max(d[i-1][0],d[i-1][1])+a[2][i];
        }

        cout << max(max(d[n][0],d[n][1]),d[n][2]) << '\n';
    }
}