// https://www.acmicpc.net/problem/14501
#include <bits/stdc++.h>
using namespace std;

// 0. d[n] : n일 최대 이익

// 1. d[n] = max(d[n], d[n-(t[x]-1)-1]+p[x]), when [n-(t[x]-1)-1]==(x-1) -> n==(x+t[x]-1)

// 2. max(d[x-1]+p[x], d[x+t[x]-1]) = d[x+t[x]-1]

const int MX = 1'500'000 + 50 + 1;
int t[MX];
int p[MX];
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        d[i+t[i]-1] = max(d[i+t[i]-1], d[i-1]+p[i]);
        d[i] = max(d[i],d[i-1]);
    }
    
    cout << d[n];
}