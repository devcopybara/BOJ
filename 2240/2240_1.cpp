// https://www.acmicpc.net/problem/2240
#include <bits/stdc++.h>
using namespace std;

const int MXT = 1'002;
const int MXW = 32;

int cnt[2][MXT][MXW];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, w;
    cin >> t >> w;

    
    int x, y;
    cin >> x;
    x = x - 1; 
    y = 1 - x;

    if(x==0) cnt[x][1][0] = 1;
    if(x==1) cnt[x][1][1] = 1;

    for(int i = 2; i <= t; i++) {
        cin >> x;
        x = x - 1; 
        y = 1 - x;

        cnt[x][i][0] = cnt[x][i-1][0]+1;
        cnt[y][i][0] = cnt[y][i-1][0];
        for(int j = 1; j <= w; j++) {
            cnt[x][i][j] = max(cnt[x][i-1][j]+1,cnt[y][i-1][j-1]+1);
            cnt[y][i][j] = max(cnt[y][i-1][j],cnt[x][i-1][j-1]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= w; i++) {
        ans = max(ans,cnt[0][t][i]);
        ans = max(ans,cnt[1][t][i]);
    }
    cout << ans;
}