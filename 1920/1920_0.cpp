#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100005];

int binary_search(int k) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l+r) / 2;
        if(arr[m] > k) r = m-1;
        else if(arr[m] < k) l = m+1;
        else return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    stable_sort(arr, arr + n);
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        cout << binary_search(k) << '\n';
    }
}