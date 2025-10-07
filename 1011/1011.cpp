// https://www.acmicpc.net/problem/1011
// 1	1	        1
// 2	1 1	        2
// 3	1 1 1	    3
// 4	1 2 1	    3
// 5	1 2 1 1	    4
// 6	1 2 2 1	    4
// 7	1 2 2 1 1	5
// 8	1 2 2 2 1	5
// 9	1 2 3 2 1	5
// 10	1 2 3 2 1 1	6 -> 1 2 3 [1] 2 1 (가운데에 [3]까지 탑을 쌓는 것과 같다.)
// 왼쪽과 오른쪽 동일하게 1~x까지 차례로 탑을 쌓고, 가운데에 1~(x+1)까지 2개를 탑을 쌓는 과정과 같다.
// 1. 왼쪽과 오른쪽 쌓인 x를 계산
// 2. 가운데 2개의 (x+1) 중 어느정도 쌓았는지 계산
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uint64;
uint64 t, x, y;
uint64 solve(uint64 n) {
    uint64 i = 0;
    // 1. 왼쪽과 오른쪽 쌓인 x를 계산
    while((i + 1) * (i + 2) <= n)
        i++;
    // 2. 가운데 2개의 (x+1) 중 어느정도 쌓았는지 계산
    // 2-1. (x+1) 0개인 경우
    if(i * (i+1) == n) return 2*i;
    // 2-1. (x+1) 1개를 쌓는 중인 경우
    if(i * (i+1) + (i+1) >= n) return 2*i + 1;
    // 2-1. (x+1) 2개를 쌓는 중인 경우
    return 2*i+2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << solve(y-x) << '\n';
    }
}