#include <bits/stdc++.h>
using namespace std;

const int MX = 500002;
bool vis[MX][2];
queue<int> Q;
int n, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    vis[n][0] = 1;
    Q.push(n);

    int cnt = 0;
    while(1) {
        cnt++;
        k += cnt;
        if(k > 500000) break;

        int qs = Q.size();
        while(qs--) {
            int curX = Q.front(); Q.pop();

            for(int nx : {curX - 1, curX + 1, curX * 2}) {
                if(nx < 0 || nx >= MX) continue;
                if(vis[nx][cnt&1]) continue;

                vis[nx][cnt&1] = 1;
                Q.push(nx);
            }
        }

        if(vis[k][cnt&1]) {
            cout << cnt;
            return 0;
        }
    }

    cout << -1;
    return 0;
}