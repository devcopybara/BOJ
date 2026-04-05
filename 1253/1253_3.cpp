// https://www.acmicpc.net/problem/3151
#include <bits/stdc++.h>
using namespace std;

const int MX = 2'005;
int arr[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr,arr+n);

    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            if(j == i) continue;

            int k = lower_bound(arr,arr+n,arr[i]-arr[j])-arr;
            
            if(k == n) continue;

            if(k == i || k == j) k++;
            if(k == i || k == j) k++;

            if(arr[k] == arr[i]-arr[j]) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}