// https://www.acmicpc.net/problem/2110
// 1. O(NM) 풀이 : 최장구간 탐색후 휴개소 추가 반복
// 2. O(MlgN) 풀이 : 최장구간 탐색 heap
// 3. O(NlgL) 풀이 : 특정 최장구간을 만들기 위해 필요한 휴개소의 개수 탐색
#include <bits/stdc++.h>
using namespace std;
int n, m, l;
int arr[50];
vector<int> len;

int cur_m(int x){
    // 추가로 필요한 최소한의 휴게소 개수
    int must_cnt = 0;
    int pre = 0;
    for (int i = 0; i <= n; i++) {
        int dist = arr[i] - pre;

        if (dist >= x) {
            // 빈 구간 : 7, 구간 최댓값 2 일때 필요한 휴게소 개수는 7/2 = 3개
            if (dist % x != 0)  must_cnt += dist / x;
            // 빈 구간 : 8, 구간 최댓값 2 일때 필요한 휴게소 개수는 8/2 - 1 = 3개
            else must_cnt += (dist / x - 1);
        }
        pre = arr[i];
    }
    return must_cnt;
    // 휴게소 개수가 m보다 크다면, 구간 최댓값은 커져야함 (휴게소 개수 감소)
    if (must_cnt > m) return true;
    // 휴게소 개수가 m보다 같거나 작다면, 구간 최댓값은 작아져도 됨 (휴게소 개수 증가 가능)
    // 위 for문에서 dist >= mid를 한번도 만족하지 못한 경우(must_cnt == 0), 구간 최댓값은 작아져야 함
    else return false;
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
    int st = 1, en = l-1;
    while(st < en){
        int mid = (st+en)/2;
        if(cur_m(mid) > m) st = mid+1;
        else en = mid;
    }
    cout << st;
}