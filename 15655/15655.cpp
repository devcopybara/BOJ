#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
int num[10];
void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << num[arr[i]] << ' ';
        cout << '\n';
        return;
    }
    int s = k == 0 ? 0 : arr[k - 1] + 1;
    for(int i = s; i < n; i++) {
        arr[k] = i;
        func(k + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    func(0);
}