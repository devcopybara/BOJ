// https://www.acmicpc.net/problem/2623
#include <bits/stdc++.h>
using namespace std;

const int MX = 1'005;
vector<int> adj[MX];
int deg[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        int pre;
        cin >> pre;
        for(int j = 0; j < k-1; j++) {
            int cur;
            cin >> cur;
            deg[cur]++;
            adj[pre].push_back(cur);
            pre = cur;
        }
    }

    vector<int> res;

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    if(res.size() < n) 
        cout << 0;
    else
        for(int x : res) cout << x << '\n';
}