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

int n;
int OOB(int x, int y) {
    return (x < 1 || x > n || y < 1 || y > n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        d[i][i] = 1;
        for(int j = 1; j <= n; j++) {
            int s = i - j;
            int e = i + j;
            if(OOB(s,e)) break;
            if(a[s] != a[e]) break;
            d[s][e] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i] != a[i+1]) continue;
        d[i][i+1] = 1;
        for(int j = 1; j <= n; j++) {
            int s = i - j;
            int e = i+1 + j;
            if(OOB(s,e)) break;
            if(a[s] != a[e]) break;
            d[s][e] = 1;
        }
    }

    int m; cin >> m;
    while(m--) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << '\n';
    }
}