#include <bits/stdc++.h>
using namespace std;

const int MX = 5000000;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    deque<pair<int, int>> DQ;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;

        // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 합니다.
        // deque안의의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은값은 항상 맨앞(front)에 있는 상태를 가지게 됩니다.
        while (!DQ.empty() && DQ.back().second >= a) {
            DQ.pop_back();
        }

        // 새로운 숫자는 항상 삽입됩니다.
        DQ.push_back({i, a});

        // 주어진 구간을 벗어나는 outdate된 숫자들은 제거해줍니다.
        if (DQ.front().first <= i - m) {
            DQ.pop_front();
        }

        cout << DQ.front().second << " ";
    }
}