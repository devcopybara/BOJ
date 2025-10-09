// https://www.acmicpc.net/problem/2110
// 1. O(NM) 풀이 : 최장구간 탐색후 휴개소 추가 반복
// 2. O(MlgN) 풀이 : 최장구간 탐색 heap
// 3. O(NlgL) 풀이 : 특정 최장구간을 만들기 위해 필요한 휴개소의 개수 탐색
#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int arr[50];
vector<int> len;

int cur_m(int max_len) {
    int tot = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 1;
        while((len[i]+cnt-1)/cnt > max_len) {
            cnt++;
        }
        tot += cnt-1;
    }
    return tot;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l;
    // 구간 위치
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    arr[n++] = l;
    // 구간 길이
    len.push_back(arr[0]);
    for(int i = 1; i < n; i++) len.push_back(arr[i]-arr[i-1]);
    sort(len.begin(),len.end());
    // 최장구간 길이 이분탐색
    int st = 1;
    int en = l-1;
    while(st<en) {
        int mid = (st+en)/2;
        if(cur_m(mid) > m) st = mid+1;
        else en = mid;
    }
    cout << st;
}