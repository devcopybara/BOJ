// https://www.acmicpc.net/problem/2302
// 연속된 좌석들의 각 가짓수를 곱하는 문제
// 1. 테이블
// D[i] = i개의 좌석에서 모든 가짓수
// 2. 점화식
// D[k] = ?
// 가장 왼쪽을 그대로 두는 경우 : D[k-1]
// 가장 왼쪽을 바꾸는 경우 : D[k-2]
// D[k] = D[k-1] + D[k-2]
// 3. 초기값
// D[1] = 1, D[2] = 2
// 연속된 좌석들의 각 가짓수를 곱하여 출력

#include <bits/stdc++.h>
using namespace std;

int n, m;
int vip[45];
int d[45];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vip[k] = 1;
    }

    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= 40; i++)
        d[i] = d[i-1] + d[i-2];

    int ans = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(vip[i]) {
            ans *= d[cnt];
            cnt = 0;
        }
        else 
            cnt++;
    }
    cout << ans * d[cnt];
}