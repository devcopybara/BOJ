// https://www.acmicpc.net/problem/14956
#include <bits/stdc++.h>
using namespace std;

int64_t ans[2];
int64_t dx[4] = {1,0,-1,0};
int64_t dy[4] = {0,1,0,-1};

void solve(int64_t n, int64_t m, int64_t x, int64_t y, int64_t d) {
    if(n == 1) {
        ans[0] = y, ans[1] = x;
        return;
    }

    int64_t np2 = n/2;
    int64_t mpn = m/(np2*np2);

    int64_t xx = x;
    int64_t yy = y;
    for(int64_t dir = 0; dir < mpn; dir++) {
        xx += np2 * dx[(dir+d)%4];
        yy += np2 * dy[(dir+d)%4];
    }
    if(mpn == 3) {
        for(int64_t dir = 0; dir < 2; dir++) {
            xx += (np2-1) * dx[(dir+d)%4];
            yy += (np2-1) * dy[(dir+d)%4];
        }
    }
    
    int64_t dd = d;
    if(mpn == 0) {
        dd = (d + 1) % 4;
    }
    else if(mpn == 3) {
        dd = (d + 3) % 4;
    }

    if(mpn == 0 || mpn == 3) {
        if(dd & 1) {
            dx[0] = -dx[0];
            dx[2] = -dx[2];
        }
        else {
            dy[1] = -dy[1];
            dy[3] = -dy[3];
        }
    }

    solve(np2, m-mpn*np2*np2, xx, yy, dd);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n, m;
    cin >> n >> m;

    solve(n,m-1,1,1,0);
    cout << ans[0] << " " << ans[1];
}
