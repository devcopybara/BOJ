// https://www.acmicpc.net/problem/20366
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[605];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int ans = 1'000'000'000;
    
    for(int a = 0; a < n-1; a++) {
        for(int d = a+1; d < n; d++) {
            int c = d-1;
            for(int b = a+1; b < c; b++) {
                while(b < c && arr[a]+arr[d] < arr[b]+arr[c]) {
                    ans = min(ans, arr[b]+arr[c]-arr[a]-arr[d]);
                    c--;
                }
                if(b < c) ans = min(ans, arr[a]+arr[d]-arr[b]-arr[c]);
            }
        }
    }

    cout << ans;
}