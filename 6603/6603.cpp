#include <bits/stdc++.h>
using namespace std;

int n;
int num[49];
int arr[49];

void func(int k) {
    if(k == 6) {
        for(int i = 0; i < 6; i++)
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
    while(1) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> num[i];
        func(0);
        cout << '\n';
    }
}