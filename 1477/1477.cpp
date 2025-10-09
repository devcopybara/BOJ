// https://www.acmicpc.net/problem/2110
// 1. O(NM) 풀이 : 최장구간 탐색후 휴개소 추가 반복
// 2. O(MlgN) 풀이 : 최장구간 탐색 heap
// 3. O(lgL) 풀이 : 특정 최장구간을 만들기 위해 필요한 휴개소의 개수 탐색
#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int arr[50];
vector<int> len;

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
    // 추가 휴개수 개수
    vector<int> num(n, 1);
    // 휴개수 추가
    while(m--) {
        // 최장구간 탐색
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            int max_len = (len[maxi] + num[maxi] - 1) / num[maxi];
            int cur_len = (len[i] + num[i] - 1) / num[i];
            if(max_len < cur_len) maxi = i;
        }
        // 휴개소 추가
        num[maxi]++;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cur_len = (len[i] + num[i] - 1) / num[i];
        ans = max(ans, cur_len);
    }
    cout << ans;
}