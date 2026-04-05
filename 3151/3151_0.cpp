// https://www.acmicpc.net/problem/3151
// https://www.acmicpc.net/problem/2467
// 1. O(N^2) 풀이 : 10'000'000'000 > 500'000'000
// 2. O(nC2) 풀이 : 5'000'000'000 > 500'000'000
// 3. O(NlgN) 100'000 x lg100'000 = 30'000'000 < 500'000'000
// 배열의 각 원소에 대해서 자신의 역수과 가장 가까운 값을 더해보면 되지 않을까?
// 이진탐색으로 통해 각 원소의 역수 또는 역수와 근접한 값의 위치를 찾아서 더해본다
// 역수가 없을 경우 역수보다 큰 값을 찾고 직전 값도 같이 계산
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    int64 ans = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int idx = lower_idx(-arr[i]-arr[j]);
            if(idx!=n && idx!=i && idx!=j) {
                if(arr[idx]+arr[i]+arr[j] == 0) {
                    ans += upper_idx(arr[idx]) - idx;
                }
            }
        }
    }
    cout << ans / 3;
}