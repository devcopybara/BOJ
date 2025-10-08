// https://www.acmicpc.net/problem/1654
#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[10'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;

    int max_len = 0;
    
    for(int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
        max_len = max(max_len, tmp);
    }

    for(int len = max_len; len > 0; len--) {
        long long cnt = 0;
        for(int i = 0; i < k; i++)
            cnt += arr[i] / len;
        if(cnt >= n) {
            cout << len;
            break;
        }
    }
}