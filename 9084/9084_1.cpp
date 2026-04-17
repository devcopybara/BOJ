// https://www.acmicpc.net/problem/9084
#include <bits/stdc++.h>
using namespace std;

const int MXN = 25;
const int MXM = 10'005;
int a[MXN];
int d[MXN][MXM*2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int m; cin >> m;
        
        for(int i = 1; i <= n; i++) fill(d[i],d[i]+1+m,0);
        
        d[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                d[i][j] += d[i-1][j];
                d[i][j+a[i]] += d[i][j];
            }
        }
        cout << d[n][m] << '\n';
    }
}