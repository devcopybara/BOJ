#include <bits/stdc++.h>
using namespace std;

// pair<x, y>를 반환하는 재귀 함수
pair<int, int> solve(int n, int m) {
    // 기저 사례: 2x2 격자일 때
    if (n == 2) {
        if (m == 0) return {1, 1};
        if (m == 1) return {1, 2};
        if (m == 2) return {2, 2};
        return {2, 1};
    }

    int half = n / 2;
    int section_size = half * half;
    int section = m / section_size; // 몇 번째 사분면인지 (0~3)
    int remain = m % section_size;  // 사분면 내에서의 순서

    pair<int, int> pos = solve(half, remain);
    int x = pos.first;
    int y = pos.second;

    // 사분면별 회전 및 이동 로직
    if (section == 0) {
        // 1사분면: y, x 대칭
        return {y, x};
    } else if (section == 1) {
        // 2사분면: 위로 이동
        return {x, y + half};
    } else if (section == 2) {
        // 3사분면: 대각선 위로 이동
        return {x + half, y + half};
    } else {
        // 4사분면: 회전 및 오른쪽으로 이동
        return {2 * half - y + 1, half - x + 1};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> result = solve(n, m - 1);
    cout << result.first << " " << result.second << "\n";

    return 0;
}