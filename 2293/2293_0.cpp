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
int d[105][100005];

int getD(int i, int j) {
    if(j < 0) return 0;
    if(d[i][j] != -1) return d[i][j];
    return getD(i-1,j) + getD(i,j-coin[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    sort(coin + 1, coin + n + 1);
    
    for(int i = 1; i <= n; i++)
        fill(d[i], d[i] + k + 1, -1);

    for(int i = 1; i <= n; i++)
        d[i][0] = 1;

    cout << getD(n,k);
}