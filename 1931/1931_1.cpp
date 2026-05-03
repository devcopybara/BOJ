// https://www.acmicpc.net/problem/1931

// 회의실을 사용할 수 있는 회의의 최대 개수

// 1. 가설
// (종료 시간,시작 시간)을 오름차순으로 정렬하고,
// 먼저 종료하는 회의 중 먼저 시작하는 회의를 기준으로 배정

// 2. 증명 - 귀류법
// 먼저 종료하는 회의 중 먼저 시작하는 회의를 기준으로 배정하는 것은 최대 개수가 아니라고 가정한다.
// 그렇다면 따로 최대 회의 개수를 위한 배치 존재한다고 하였을 때, 
// 특정 회의를 이전 회의 종료 후 가장 먼저 종료하는 회의 중 먼저 시작하는 회의를 대신 배정하였다고 했을 때,
// 새로운 배치보다 더 많은 배치는 존재하지 않다.
// 그러므로 가정은 거짓이고 가설은 참이다.

#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define X first
#define Y second

const int MX = 100'005;
pii a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e; cin >> s >> e;
        a[i] = {e,s};
    }
    sort(a, a+n);

    int ans = 0;
    int t = 0;
    for(int i = 0; i < n; i++) {
        if(t <= a[i].Y) {
            t = a[i].X;
            ans++;
        }
    }
    cout << ans;
}