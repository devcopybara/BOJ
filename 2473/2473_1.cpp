// https://www.acmicpc.net/problem/2473
#include <bits/stdc++.h>
using namespace std;

const int64_t MX = 5'000;
int64_t arr[MX];

int64_t n;
int64_t sum;
int64_t ans[3] = {0,1,2};
void check(int64_t i, int64_t j, int64_t k) {
    if(k < 0 || k >= n) return;
    if(k==i || k==j) return;

    int64_t _sum = abs(arr[i]+arr[j]+arr[k]);
    if(sum > _sum) {
        sum = _sum;
        ans[0] = i, ans[1] = j, ans[2] = k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int64_t i = 0; i < n; i++) cin >> arr[i];
    
    sort(arr,arr+n);
    sum = abs(arr[0]+arr[1]+arr[2]);

    for(int64_t i = 0; i < n; i++) {
        for(int64_t j = i+1; j < n; j++) {
            int64_t k = lower_bound(arr+j+1,arr+n,-(arr[i]+arr[j]))-arr;
            check(i,j,k);
            check(i,j,k-1);
        }
    }

    for(int64_t i = 0; i < 3; i++) cout << arr[ans[i]] << ' ';
}