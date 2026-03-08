#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;

int n;
int w[305];
int adj[305][305];
bool chk[305];

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) 
        cin >> w[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adj[i][j];

    for(int i = 1; i <= n; i++)
        pq.push({w[i], i});

    int ans = 0;
    int cnt = 0;

    while(cnt < n) {
        auto cur = pq.top(); pq.pop();

        int cost = cur.X;
        int v = cur.Y;

        if(chk[v]) continue;
        chk[v] = true;
        ans += cost;
        cnt++;

        for(int i = 1; i <= n; i++) {
            if(!chk[i] && adj[v][i] > 0) {
                pq.push({adj[v][i], i});
            }
        }
    }

    cout << ans;
}
