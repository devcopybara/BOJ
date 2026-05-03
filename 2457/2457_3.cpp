// https://www.acmicpc.net/problem/2457

// 0. 문제
// 꽃은 피는 날과 지는 날이 정해져 있다.
// 1. 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
// 2. 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다. 
// N개의 꽃들 중에서 위의 두 조건을 만족하는 선택한 꽃들의 최소 개수

// 1. 문제 정의
// 0301~1130 매일 1가지 이상 피어 있도록 꽃들을 선택할 때 최소 개수?

// 2. 풀이
// 현재 날짜 이전에 시작해서 가장 늦게 끝나는 꽃

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define X first
#define Y second
const int MX = 100'005;
pii a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int sm,sd,em,ed;
        cin >> sm >> sd >> em >> ed;
        a[i] = {sm*100+sd, em*100+ed};
    }
    sort(a,a+n);

    int t = 301;
    int ans = 0;

    int i = 0;
    while(t <= 1130) { 
        int nt = t;

        while(i < n && a[i].X <= t) {
            nt = max(nt, a[i].Y);
            i++;
        }

        if(nt == t) break;

        t = nt;
        ans++;
    }

    if(t <= 1130) cout << 0;
    else cout << ans;
}