// https://www.acmicpc.net/problem/1744
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int ans = 0;
    int i = n - 1;
    while(i >= 0) {
        if(arr[i] > 1) {
            if(i > 0 && arr[i-1] > 1) {
                ans += arr[i] * arr[i-1];
                i -= 2;
            }
            else {
                ans += arr[i];
                i--;
            }
        }
        else if(arr[i] == 1) {
            ans += arr[i];
            i--;
        }
        else {
            if((i + 1) & 1) {
                ans += arr[i];
                i--;
            }
            else {
                ans += arr[i] * arr[i-1];
                i -= 2;
            }
        }
    }
    cout << ans;
}