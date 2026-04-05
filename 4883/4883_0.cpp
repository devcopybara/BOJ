// https://www.acmicpc.net/problem/4883
#include <bits/stdc++.h>
using namespace std;

// d[n] = 가장 위쪽 가운데 정점에서 가장 아래쪽 가운데 정점으로 가는 최단 경로 
// d[n] = 최단경로

// d[k] = min(d[k-1] + 비용)
// d[k][0],d[k][1],d[k][2] : 왼쪽/중앙/오른쪽 지점 최단경로
// d[k][0] = min(d[k-1][0],d[k-1][1]                  )+a[k][0]
// d[k][1] = min(d[k-1][0],d[k-1][1],d[k-1][2],d[k][0])+a[k][1]
// d[k][2] = min(d[k-1][1],d[k-1][2]          ,d[k][1])+a[k][2]

const int64_t MX = 100'005;
int64_t a[MX][3];
int64_t d[MX][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t t = 0; 
    while(1) {
        int64_t n;
        cin >> n;
        if(n == 0) break;
        for(int64_t i = 1; i <= n; i++)
            fill(d[i],d[i]+3,0);
    
        for(int64_t i = 1; i <= n; i++)
            for(int64_t j = 0; j < 3; j++)
                cin >> a[i][j];

        d[1][0] = a[1][1];
        d[1][1] = a[1][1];
        d[1][2] = a[1][1] + a[1][2];

        for(int64_t k = 2; k <= n; k++) {
            d[k][0] = min(d[k-1][0],d[k-1][1])+a[k][0];
            d[k][1] = min(min(min(d[k-1][0],d[k-1][1]),d[k-1][2]),d[k][0])+a[k][1];
            d[k][2] = min(min(d[k-1][1],d[k-1][2]),d[k][1])+a[k][2];
        }

        cout << ++t << ". " << d[n][1] << "\n";
    }
}