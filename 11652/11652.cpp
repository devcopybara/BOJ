// https://www.acmicpc.net/problem/11652
#include <bits/stdc++.h>
using namespace std;

int n;
const int MX = 100005;
long long arr[MX];
bool chk[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    arr[0] = arr[1] - 1;
    arr[n + 1] = arr[n] + 1;

    long long mxval = arr[0], mxcnt = 0,cnt = 0;
    for(int i = 0; i <= n; i++) {
        if(arr[i] != arr[i+1]) {
            if(mxcnt < cnt) {
                mxval = arr[i];
                mxcnt = cnt;
            }
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    cout << mxval;
}