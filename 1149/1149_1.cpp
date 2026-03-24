// https://www.acmicpc.net/problem/1149

// f(모든 집을 칠하는 비용의 최솟값을 얻는데 필요한 파라미터) = 모든 집을 칠하는 비용의 최솟값
// f(1~n번째 집을 칠하는 비용의 최솟값을 얻는데 필요한 파라미터) = 1~n번째 집을 칠하는 비용의 최솟값
// f(n) = n번째까지 집을 칠하는 비용의 최솟값
// f(n) = min(n번째 집을 R로 칠했을 경우 비용, n번째 집을 G로 칠했을 경우 비용, n번째 집을 B로 칠했을 경우 비용)
// f(n) = min(n번째 집을 R로 칠할 수 있는 상태에서 R로 칠할 때 비용, ...)

// f(0) = min(tot[0]), tot[0] = [0,0,0]
// f(1) = min(tot[1]), tot[1] = [min(tot[0][2],tot[0][3])+cost[1][0], ...]
// ...
// f(k) = min(tot[k]), tot[k] = [min(tot[k-1][2],tot[k-1][3])+cost[k][0], ...]

#include <bits/stdc++.h>
using namespace std;

const int MX = 1002;
int tot[MX][3];
int cost[MX][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i][0];
        cin >> cost[i][1];
        cin >> cost[i][2];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            tot[i][j] = cost[i][j] + min(tot[i-1][(j+1)%3],tot[i-1][(j+2)%3]);
        }
    }

    cout << min(min(tot[n][0],tot[n][1]),tot[n][2]);
}