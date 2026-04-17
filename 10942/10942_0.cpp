// https://www.acmicpc.net/problem/10942

// 이전 상태를 알면 현재 상태를 구할 수 있다 -> DP

// 1. 테이블
// d[i][j] : i부터 j까지 문자열이 팰린드롬 여부
// 2. 점화식
// d[i][j] = (d[i+1][j-1] == 1 && a[i] == a[j]) 을 만족하면 1, 아니면 0
// 3. 초기값
// i==j, j==i+1

#include <bits/stdc++.h>
using namespace std;

const int MX = 2'005;
int a[MX];
int d[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        d[i][i] = 1;
        if(a[i] == a[i+1]) d[i][i+1] = 1;
    }

    for(int s = n; s > 0; s--) {
        for(int e = s+2; e <= n; e++) {
            d[s][e] = (d[s+1][e-1]==1 && a[s]==a[e]);
        }
    }

    int m; cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}