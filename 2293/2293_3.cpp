// https://www.acmicpc.net/problem/2293
#include <bits/stdc++.h>
using namespace std;

// d[k] = n가지 종류의 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하는 경우의 수
// d[k] = n가지 동전 k원 조합수

// 1. k원의 조합수
// d[k] = (1) + d[k-1]*d[1] + d[k-2]*d[2] + ..

// 2. n가지 동전 k원 조합수
// d[n][k] = (1) + d[k-1][n]*d[1][n] + d[k-2][n]*d[2][n] + ..  : 같은 조합인지 확인 불가

// 3. n가지 동전 k원 조합수
// d[n][k] = (1) + d[k-coin[n]][n-1] + d[k-coin[n]*2][n-1] + .. : 새로운 조합만 보장

const int MXN = 105;
const int MXK = 10'005;
int coin[MXN];
// int d[MXN][MXK];
int cur[MXK];
int pre[MXK];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    // for(int i = 0; i <= n; i++)
    //     d[i][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        pre[0] = 1;
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k <= j; k += coin[i]) {
                // d[i][j] += d[i-1][j-k];
                cur[j] += pre[j-k];
            }
        }

        memcpy(pre,cur,(m+1)*sizeof(int));
        memset(cur,0,(m+1)*sizeof(int));
    }

    // cout << d[n][m];
    cout << pre[m];
}