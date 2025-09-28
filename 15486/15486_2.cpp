// https://www.acmicpc.net/problem/15486
// 1. 테이블 정의
// D[k]=1일부터 i일까지 상담했을떄 얻을 수 있는 최대 이익
// 2. 점화식 찾기
// D[k+t[k]-1]=max(D[k+t[k]-1],P[k]+D[k-1]) : 새로운 가능성에 대해 미리 1번만 계산
// D[k]=max(D[k],D[k-1]) : 미리 계산된 값이 없으면, 새로운 가능성이 없으므로, 현재 최대값은 직전 최대값
// 3. 초기값 정의
// D[0]=0

#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 1500055;
int t[MX], p[MX], d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    for(int i = 1; i <= n; i++) {
        d[i+t[i]-1]=max(d[i+t[i]-1],p[i]+d[i-1]);
        d[i] = max(d[i],d[i-1]);
    }
    cout << d[n];
}