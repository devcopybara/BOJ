// https://www.acmicpc.net/problem/3151
#include <bits/stdc++.h>
using namespace std;

const int MX = 10'005;
int arr[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr,arr+n);

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ans += upper_bound(arr+j+1,arr+n,-arr[i]-arr[j])-lower_bound(arr+j+1,arr+n,-arr[i]-arr[j]);
        }
    }

    cout << ans;
}