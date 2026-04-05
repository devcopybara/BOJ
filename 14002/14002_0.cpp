// https://www.acmicpc.net/problem/14002
// 1. 테이블
// D[i] = i의 원소로 만들 수 있는 가장 긴 증가하는 부분 수열의 길이
// 2. 점화식
// D[i] = 
// 3. 초기값
// D[1] = 1
// 4. 출력
// A의 가장 긴 증가하는 부분 수열의 길이, 원소

#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;
int n;
int arr[MX];
int d[MX];
int pre[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    fill(d, d + n, 1);
    
    int maxd = 1;
    int maxi = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = i - 1; j > 0; j--) {
            if(arr[j] < arr[i] && d[j] >= d[i]) {
                d[i] = d[j] + 1;
                pre[i] = j;
            }
        }
        if(d[i] > maxd) {
            maxd = d[i];
            maxi = i;
        }
    }

    vector<int> ans;
    int cur = maxi;
    while(cur) {
        ans.push_back(arr[cur]);
        cur = pre[cur];
    }
    cout << maxd << '\n';
    for(int i = maxd - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}