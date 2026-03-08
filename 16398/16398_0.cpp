#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;
int n;
int adj[1002][1002];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> chk(1002,false);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adj[i][j];

    chk[1] = true;
    for(int i = 1; i <= n; i++)
        if(!chk[i] && adj[1][i]) 
            pq.push({adj[1][i],i});

    long long ans = 0;
    int cnt = 0;

    while(cnt < n-1) {
        auto cur = pq.top(); pq.pop();
        int cost = cur.X;
        int u = cur.Y;

        if(chk[u]) continue;
        chk[u] = true;
        ans += cost;
        cnt++;

        for(int i = 1; i <= n; i++)
            if(!chk[i] && adj[1][i]) 
                pq.push({adj[u][i],i});
    }

    cout << ans;
}