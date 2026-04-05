// https://www.acmicpc.net/problem/2110
// 1. O(nCc) 풀이법 : 시간초과
// 2. O(NlgN) 풀이법 : 200,000 * 400 = 80,000,000 < 500,000,000 => 이분탐색 : C개와 같은 목표거리를 위해 필요한 공유기의 개수 이분탐색
#include <bits/stdc++.h>
using namespace std;
int n, c;
int a[200'000];

int func(int max_len) {
    int cnt = 1; // a[0] 무조건 설치
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(a[i]-a[idx] >= max_len) {
            cnt++;
            idx = i;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int st = 0;
    int en = a[n-1] - a[0];
    while(st<en) {
        int mid = (st+en+1)/2;
        if(func(mid) < c) en = mid-1;
        else st = mid;
    }
    cout << st;
}