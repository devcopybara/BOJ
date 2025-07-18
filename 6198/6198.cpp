// 현재 건물 보다 낮은 다음 건물의 개수 출력
// 각 위치의 건물마다 자신 보다 높은 다음 건물의 위치 필요
// 즉 현재 건물에서 알 수 없으므로 다음 건물 높이를 알고 다시 위치로 돌아와 거리 출력

// 비효율을 줄이기 위해 역순으로 진행
// 다음 건물 높이와 위치 정보를 저장해서 역순으로 처리

// 이때 현재 건물이 필요한 데이터는 다음 건물 중 자신 보다 높은 다음 건물의 위치 필요
// 현재 건물 보다 작은 건물의 데이터는 버리고 자신 보다 높은 다음 건물의 (위치, 높이) 저장
// 즉 건물의 높이를 기준으로 내림차순 (위치, 높이) 자료 구조 정렬 => 스택

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
stack<pair<int,int>> S;

const int MX = 80002;
int y[MX];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }

    long long ans = 0;
    S.push({n - 1, y[n - 1]});
    for(int x = n - 2; x >= 0; x--) {
        while(!S.empty() && y[x] > S.top().Y) {
            S.pop();
        }
        if(S.empty()) {
            ans += n - 1 - x;
        }
        else {
            ans += S.top().X - 1 - x;
        }
        S.push({x, y[x]});
    }
    cout << ans;
}