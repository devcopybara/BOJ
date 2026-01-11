// 현재 높이 보다 높은 이전 높이의 위치 출력
// 높이를 기준으로 내림차순 자료 정렬 (높이, 위치)
// 스택을 사용하여 높이를 내림차순 자료 정렬 유지

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

stack<pair<int,int>> S;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int y;
    cin >> y;
    cout << "0 ";
    S.push({1, y});

    for(int x = 2; x <= n; x++) {
        cin >> y;
        while(!S.empty() && S.top().Y <= y) {
            S.pop();
        }
        if(S.empty()) {
            cout << "0 ";
        }
        else {
            cout << S.top().X << ' ';
        }
        S.push({x, y});
    }
}