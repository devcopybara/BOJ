// https://www.acmicpc.net/problem/11659
// d[k]=1~k까지의 합=d[k-1]+arr[k];

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100001];
int acc[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        acc[i] = tmp + acc[i - 1];
    }

    while(m--) {
        int i, j;
        cin >> i >> j;
        cout << acc[j] - acc[i-1] << '\n';
    }
}