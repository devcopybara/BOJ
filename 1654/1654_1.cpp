// https://www.acmicpc.net/problem/1654
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int n, k;
int arr[10'005];

int64 get_cnt(int64 len) {
    int64 cnt = 0;
    for(int i = 0; i < k; i++)
        cnt += arr[i] / len;
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for(int i = 0; i < k; i++) cin >> arr[i];

    int64 st = 1;
    int64 en = 0x7fffffff;
    while(st < en) {
        int64 mid = (st+en+1)/2;
        if(get_cnt(mid) < n) en = mid-1;
        else st = mid;
    }
    cout << st;
}