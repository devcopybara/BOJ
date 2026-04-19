// https://www.acmicpc.net/problem/2482

// 현재 상태를 구하기 위해 이전 상태가 필요한가?
// 현재 상태 : d'[n][k] : 원형 N의 인접하지 않게 K개 선택 경우의 수
// 현재 상태 : d[n][k] : 선형 N의 인접하지 않게 K개 선택 경우의 수
// 이전 상태 : d[n-2][k-1], d[n-1][k]
// d[n][k] = d[n-2][k-1] + d[n-1][k]
// d'[n][k] = d[n-3][k-1] + d[n-1][k]

#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
const int DIV = 1'000'000'003;
int d[MX][MX];

int getD(int n, int k) {
    if(n < 0) return 0;
    if(d[n][k] != -1) return d[n][k];

    if(n == 0) return d[n][k] = (k == 0);
    if(k == 0) return d[n][k] = 1;
    if(k == 1) return d[n][k] = n;
    if(k > (n+1)/2) return d[n][k] = 0;

    return d[n][k] = (getD(n-2,k-1) + getD(n-1,k)) % DIV;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i <= n; i++) fill(d[i],d[i]+k+1,-1);
    cout << (getD(n-3,k-1) + getD(n-1,k)) % DIV;
}