#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[1000000], b[1000000], c[2000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        c[k++] = a[i] <= b[j] ? a[i++] : b[j++];
    }
    while(i < n) {
        c[k++] = a[i++];
    }
    while(j < m) {
        c[k++] = b[j++];
    }

    for(int k = 0; k < n + m; k++)
        cout << c[k] << ' ';
}