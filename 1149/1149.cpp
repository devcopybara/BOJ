// https://www.acmicpc.net/problem/1149

// D[i][0]=i집을 R로 칠할때 최소비용=R+min(D[i-1][1],D[i-1][2])
// D[i][1]=i집을 G로 칠할때 최소비용=G+min(D[i-1][0],D[i-1][2])
// D[i][2]=i집을 B로 칠할때 최소비용=B+min(D[i-1][0],D[i-1][1])
// 출력 : min(D[n][0],D[n][1],D[n][2])

#include <bits/stdc++.h>
using namespace std;

#define R 0
#define G 1
#define B 2

int n;
int d[1001][3];
int cost[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> cost[i][R] >> cost[i][G] >> cost[i][B];
    d[1][R]=cost[1][R];
    d[1][G]=cost[1][G];
    d[1][B]=cost[1][B];
    for(int i = 2; i <= n; i++) {
        d[i][R]=cost[i][R]+min(d[i-1][G],d[i-1][B]);
        d[i][G]=cost[i][G]+min(d[i-1][R],d[i-1][B]);
        d[i][B]=cost[i][B]+min(d[i-1][R],d[i-1][G]);
    }
    cout << min(min(d[n][R],d[n][G]),d[n][B]);
}