// https://www.acmicpc.net/problem/22862

// bfs : (삭제 횟수,시작 위치,현재 수열의 위치) -> 홀수 삭제/짝수 재시작/짝수 추가 -> 종료/현재 수열의 위치+1
// dp : [삭제 횟수][시작 위치][현재 수열의 위치] = 최대 짝수 연속 길이
// for : 2중 for문으로 시작 위치, 끝 위치 (길이) 정하고 내부에 홀수가 k개 이하인지 확인
// tp : k개까지 홀수 추가 -> 첫번째 홀수 제외할 때까지 시작 위치 증가 -> k-1개 홀수 -> 반복

#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int cnt = 0;
    int en = 0;
    for(int st = 0; st < n; st++) {
        while(en < n) {
            if(cnt == k && (a[en] & 1)) break;
            if(a[en] & 1) cnt++;
            en++;
        }

        ans = max(ans, en-st - cnt);

        if(a[st] & 1) cnt--;
    }
    cout << ans;
}