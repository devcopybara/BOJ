// https://www.acmicpc.net/problem/5214
#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<bool>> adj(100'005, vector<bool>(100'005, false));
int dist[100'005];
int hipertube_station[100'005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < k; j++) {
            cin >> hipertube_station[j];
        }

        for(int u = 0; u < k; u++) {
            for(int v = 0; v < k; v++) {
                if(u == v) continue;
                adj[hipertube_station[u]][hipertube_station[v]] = true;
            }
        }
    }

    fill(dist,dist+1+n,-1);

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty()) {
        if(dist[n] != -1) break;
        int cur = q.front(); q.pop();
        for(int i = 1; i <= n; i++) {
            if(!adj[cur][i]) continue;
            int nxt = i;
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    cout << dist[n];
}