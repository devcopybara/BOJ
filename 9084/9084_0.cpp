// https://www.acmicpc.net/problem/9084
#include <bits/stdc++.h>
using namespace std;

const int MXN = 25;
const int MXM = 10'005;
int a[MXN];
int d[MXN][MXM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int m; cin >> m;
        
        for(int i = 1; i <= n; i++) fill(d[i],d[i]+1+m,0);
        
        for(int i = 1; i <= n; i++) {
            d[i][0] = 1;
            for(int j = 1; j <= m; j++) {
                d[i][j] += d[i-1][j]; // 금액j 1~i-1동전으로 경우의수
                if(j-a[i]>=0) d[i][j] += d[i][j-a[i]]; // 금액j-a[i] 1~i동전으로 경우의수
            }
        }
        cout << d[n][m] << '\n';
    }
}