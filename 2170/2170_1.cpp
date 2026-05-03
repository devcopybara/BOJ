// https://www.acmicpc.net/problem/2170

// 0. 문제
// 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산

// 1. 정의
// 중복과 빈곳을 제외한 선의 총길이?

// 2. 풀이
// 최소st~최대en 사이 중복과 빈곳 제외한 길이
// [중복] 현재en보다 작은st들의 최대en => en
// [빈곳] 현재en보다 큰st중 최소st => st

// st기준으로 오름차순으로 정렬하면 
// [중복] 확인을 위한 en보다 작은st들을 순서대로 찾을 수 있고,
// [빈곳] 확인을 위한 en보다 큰st중 최소st를 즉시 찾을 수 있으므로,

// st기준으로 오름차순 정렬하여
// 최소st와 en을 기준으로 시작하여
// st의 크기 순서대로 각각의 st와 기준en과 비교하여 
// 현재st가 기준en보다 작으면, [중복]으로 중복된 곳을 제외하고 나머지만 ans에 더하고, 기준en을 현재en으로 갱신
// 현재st가 기준en보다 크면, [빈곳]으로 빈 곳을 제외하고 나머지만 ans에 더하고, 기준st와 en을 현재st와 en으로 갱신

#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
#define X first
#define Y second

const int MX = 1'000'005;
pii a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x,y};
    }
    sort(a,a+n);

    int st = a[0].X, en = a[0].Y;
    int ans = en-st;

    int i = 1;
    while(i < n) {
        if(a[i].X <= en) {
            // overlap
            if(a[i].Y > en) {
                ans += a[i].Y-en;
                en = a[i].Y;
            }
        }
        else {
            // empty
            st = a[i].X, en = a[i].Y;
            ans += en-st;
        }
        i++;
    }
    cout << ans;
}