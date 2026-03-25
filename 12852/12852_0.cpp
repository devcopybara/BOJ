// https://www.acmicpc.net/problem/12852
// D[k]=3개를 적절히 사용해서 1을 만들수 있는 최솟값=min(D[k-1]+1,D[k/2]+1,D[k/3]+1)
#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000005];
int p[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1]=0;
    d[2]=1; p[2]=1;
    d[3]=1; p[3]=1;
    for(int i = 4; i <= n; i++) {
        d[i]=d[i-1]+1; p[i]=i-1;
        if(i % 2 == 0) {
            if(d[i] > d[i/2]+1) {
                d[i]=d[i/2]+1; p[i]=i/2;
            }
        }
        if(i % 3 == 0) {
            if(d[i] > d[i/3]+1) {
                d[i]=d[i/3]+1; p[i]=i/3;
            }
        }
    }
    cout << d[n] << '\n';
    while(n >= 1) {
        cout << n << ' ';
        n = p[n];
    }
}