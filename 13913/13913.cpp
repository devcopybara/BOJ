#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int pre[100002];
int arr[100002];
queue<int> Q;
int n, k;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int m = max(n, k + 1);
    fill(dist, dist + m + 1, -1);
    fill(pre, pre + m + 1, -1);

    pre[n] = n;
    dist[n] = 0;
    Q.push(n);

    while(dist[k] == -1) {
        int curX = Q.front(); Q.pop();
        
        for(int nx : {curX - 1, curX + 1, curX * 2}) {
            if(nx < 0 || nx > m ) continue;
            if(dist[nx] >= 0) continue;
            
            pre[nx] = curX;
            dist[nx] = dist[curX] + 1;
            Q.push(nx);
        }
    }

    cout << dist[k] << '\n';
    int aCnt = 0;
    for(int curX = k; curX != n; curX = pre[curX]) {
        arr[aCnt++] = curX;
    }
    arr[aCnt] = n;
    for(int i = aCnt; i >= 0; i--) {
        cout << arr[i] << ' ';
    }
}