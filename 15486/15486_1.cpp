// https://www.acmicpc.net/problem/15486
// 1. 테이블 정의
// D[k]=1일부터 i일까지 상담했을떄 얻을 수 있는 최대 이익
// 2. 점화식 찾기
// D[k]=max(P[k]+D[k-1],P[k-1]+D[k-2], ...)
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
        for(int j = i+t[i]-1; j <= n; j++)
            d[j]=max(d[j],p[i]+d[i-1]);
    }
    cout << d[n];
}