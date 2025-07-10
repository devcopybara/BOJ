#include <bits/stdc++.h>
using namespace std;

const int MX = 500001;
int vis[MX];
queue<int> Q;
int n, k;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(vis, vis + MX, -1);

    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }

    vis[n] = 0;
    Q.push(n);
    int cnt = 0;
    while(k < MX) {
        cnt++;
        k += cnt;

        int Qsize = Q.size();
        while(Qsize--) {
            int curX = Q.front(); Q.pop();

            for(int nx : {curX - 1, curX + 1, curX * 2}) {
                if(nx < 0 || nx >= MX) continue;
                if(vis[nx] >= 0) continue;

                vis[nx] = cnt;
                Q.push(nx);
            }
        }
        
        if(vis[k] >= 0 && ((cnt - vis[k]) & 1) == 0) {
            cout << cnt;
            return 0;
        }
    }

    cout << -1;
    return 0;
}