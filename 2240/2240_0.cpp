// https://www.acmicpc.net/problem/2240
// 1. 테이블
// D[i][j][k] = i초에 최대 j번 이동하여 k번 나무에 위치한 경우 받을 수 있는 최대 개수
// 2. 점화식
// D[i][j][1] = (tree[i]==1?1:0) + max(D[i-1][j-1][1],D[i-1][j-1][2],D[i-1][j][1])
// D[i][j][2] = (tree[i]==2?1:0) + max(D[i-1][j-1][1],D[i-1][j-1][2],D[i-1][j][2])
// 3. 초기값
// D[1~t][0][1~2]
// 4. 출력
// t초에 최대 w번 이동하여 받을 수 있는 최대 개수
// max(D[t][w][1],D[t][w][2])

#include <bits/stdc++.h>
using namespace std;
int t,w;
const int MXT = 1005, MXW = 35;
int d[MXT][MXW][3];
int tree[MXT];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> w;
    
    for(int i = 1; i <= t; i++)
        cin >> tree[i];
        
    for(int i = 1; i <= t; i++)
        d[i][0][1] = d[i-1][0][1] + (tree[i]==1?1:0);

    for(int i = 1; i <= t; i++) {
        for(int j = 1; j <= w; j++) {
            d[i][j][1] = (tree[i]==1?1:0) + max(d[i-1][j][1],max(d[i-1][j-1][1],d[i-1][j-1][2]));
            d[i][j][2] = (tree[i]==2?1:0) + max(d[i-1][j][2],max(d[i-1][j-1][1],d[i-1][j-1][2]));
        }
    }

    cout << max(d[t][w][1],d[t][w][2]);
}