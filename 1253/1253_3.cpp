// https://www.acmicpc.net/problem/1253
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int n;
int64 arr[100'005];
int upper_idx(int target) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(target < arr[mid]) en = mid;
        else st = mid+1;
    }
    return st;
}
int lower_idx(int target) {
    int st = 0;
    int en = n;
    while(st < en) {
        int mid = (st+en)/2;
        if(target <= arr[mid]) en = mid;
        else st = mid+1;
    }
    return st;
}
vector<bool> state(100'005, false);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    int64 ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool is_good = false;
            if(i == j) continue;
            int k = lower_idx(arr[i]-arr[j]);
            if(k == n) continue;
            for(; arr[k] == arr[i]-arr[j]; k++) {
                if(k==i || k==j) continue;
                is_good = true;
                ans++;
                break;
            }
            if(is_good) break;
        }
    }
    cout << ans;
}