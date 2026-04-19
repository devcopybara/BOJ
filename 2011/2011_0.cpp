// https://www.acmicpc.net/problem/2011

// 이전 상태를 알면 현재 상태를 구할 수 있다 -> DP

// 1.테이블
// d[i] : 해석 가짓수
// 2.점화식
// d[i] : ((s[i-1]==1) || (s[i-1]==2 && s[i]<=6)) 이면 d[i-2]+d[i-1], 아니면 d[i-1]
// 3.초기값
// d[0] = 1

#include <bits/stdc++.h>
using namespace std;

const int DIV= 1000000;
const int MX = 5'005;
char s[MX];
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> (s+1);
    
    d[0] = 1;
    int n = strlen(s+1);
    for(int i = 1; i <= n; i++) {
        if((s[i-1]=='1') || (s[i-1]=='2' && s[i]<='6')) {
            if(s[i] != '0')
                d[i] = (d[i-2]+d[i-1]) % DIV;
            else
                d[i] = d[i-2];
        }
        else {
            if(s[i] != '0')
                d[i] = d[i-1];
            else
                break;
        }
    }

    cout << d[n];
}