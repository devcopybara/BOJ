#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
vector<int> adj[105];
int deg[105];
int total_parts_cnt[105][105];
int basic_parts_cnt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y,k;
        cin >> x >> y >> k;
        total_parts_cnt[x][y] = k;
        adj[y].push_back(x);
        deg[x]++;
    }

    vector<int> basic_parts;
    queue<int> q;
    for(int i = 1; i <= n-1; i++) {
        if(deg[i] == 0) {
            q.push(i);
            basic_parts.push_back(i);
            basic_parts_cnt[i][i] = 1;
        }
    }
    sort(basic_parts.begin(), basic_parts.end());

    vector<int> result;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            total_parts_cnt[nxt][cur]
            if(deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for(int i : basic_parts) {
        if(basic_parts_cnt[n][i])
            cout << i << ' ' << basic_parts_cnt[n][i] << '\n';
    }
}