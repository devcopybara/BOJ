// https://www.acmicpc.net/problem/2579

// f(이 게임에서 얻을 수 있는 총 점수의 최댓값을 얻기 위해 필요한 파라미터) = 이 게임에서 얻을 수 있는 총 점수의 최댓값
// f(마지막 계단에서 얻을 수 있는 총 점수의 최댓값을 얻기 위해 필요한 파라미터) = 마지막 계단에서 얻을 수 있는 총 점수의 최댓값
// f(n번쨰 계단 최댓값을 얻기 위해 필요한 파라미터) = n번쨰 계단 최댓값
// f(n) = max(n번째 계단 연속x 최댓값, n번째 계단 연속o 최댓값)

// f(1) = max(tot[1][0],tot[1][1]) : tot[1][0]=X,tot[1][1]=s1
// f(2) = max(tot[2][0],tot[2][1]) : tot[2][0]=s2,tot[2][1]=x
// f(3) = max(tot[3][0],tot[3][1]) : tot[3][0]=max(tot[1][0]+s3,tot[1][1]+s3),tot[3][1]=tot[2][0]+s3
// ...
// f(k) = max(tot[k][0],tot[k][1]) : tot[k][0]=max(tot[k-2][0]+sk,tot[k-2][1]+sk),tot[k][1]=tot[k-1][0]+sk

#include <bits/stdc++.h>
using namespace std;

const int MX = 302;
int tot[MX][2];
int s[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];

    tot[1][1] = s[1];
    tot[2][0] = s[2];
    tot[2][1] = s[1]+s[2];
    for(int i = 3; i <= n; i++) {
        tot[i][0] = max(tot[i-2][0]+s[i],tot[i-2][1]+s[i]);
        tot[i][1] = tot[i-1][0]+s[i];
    }

    cout << max(tot[n][0], tot[n][1]);
}