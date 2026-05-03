// https://www.acmicpc.net/problem/1026

// S = A[0] × B[0] + ... + A[N-1] × B[N-1]
// S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 단, B에 있는 수는 재배열하면 안 된다.

// S의 최솟값?
// B를 재배열하지 않았다고 가정하고, A와 B 모두 재배열
// A의 최소값과 B의 최대값을 곱하도록 하면 S는 최소

#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
int a[MX];
int b[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i]*b[n-1-i];
    cout << s;
}