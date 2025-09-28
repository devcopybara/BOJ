// https://www.acmicpc.net/problem/2293

// 1. 테이블
// D[i] = 1~i번 동전을 사용해 합이 k원인 경우의수
// 2. 점화식
// D[i] = ?
// D[i] = D[i-1] + (i번 동전을 1번이상 사용해 k원인 경우의수)
// (i번 동전을 1번이상 사용해 k원인 경우의수) = ?
// (i번 동전을 1번이상 사용해 k원인 경우의수) = 0~(i-1)번 동전의 모든 조합의수 필요
// 0~(i-1)번 동전의 모든 조합의수 : 시간초과로 불가능
// 3. 초기값
// 

// 1. 테이블
// D[i][j] = 1~i번 동전을 사용해 j원인 경우의수
// 2. 점화식
// D[i][j] = ?
// D[n][k] = D[n-1][k] + D[n][k - coin[n]]
// D[i][j] = D[i-1][j] + D[i][j - coin[n]]
// 3. 초기값
// D[1][0~k], D[1~n][0] = 1
// 4. 결과
// D[n][k]

#include <bits/stdc++.h>
using namespace std;
int n, k;
int coin[105];
int d[100005]; // d[105][100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    sort(coin + 1, coin + n + 1);

    for(int i = 1; i <= n; i++) {
        d[0] = 1; // d[i][0] = 1;
        for(int j = 1; j <= k; j++) {
            d[j] += (j-coin[i]>=0?d[j-coin[i]]:0);
            // d[i][j] = d[i-1][j] + (j-coin[i]>=0?d[i][j-coin[i]]:0);
        }
    }

    cout << d[k];
}