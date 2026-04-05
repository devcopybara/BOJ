// https://www.acmicpc.net/problem/12015
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
int a[MX];
int d[MX];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int sz = 1;
    for(int i = 1; i <= n; i++) {
        int k = lower_bound(d,d+sz,a[i]) - d;
        if(k == sz) sz++;
        d[k] = a[i];
    }
    cout << sz-1;
}