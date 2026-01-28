// https://www.acmicpc.net/problem/19700
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
pair<int, int> a[500005];
multiset<int> s;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].X >> a[i].Y;
    // 키, 등수 내림차순 정렬
    sort(a, a + n, greater<pair<int, int>>());

    for (int i = 0; i < n; i++) {
        // 인원수는 음수로 표시
        // k보다 작은 그룹중 가장 인원이 많은 그룹 탐색
        auto it = s.lower_bound(-a[i].Y + 1);
        if (it == s.end()) {
            // 없으면 새로운 그룹
            s.insert(-1);   
        }
        else {
            // 있으면 해당 그릅에 인원 추가
            s.insert(*it - 1);
            s.erase(it);
        }
    }

    cout << s.size();
}