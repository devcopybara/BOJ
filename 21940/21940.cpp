#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int n, m, k;
int adj[202][202];
int c[202];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        fill(adj[i]+1, adj[i]+1+n, INF);
        adj[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a][b] = t;
    }

    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> c[i];
    
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    vector<int> ans;
    int min_max_dist = INF;
    for(int t = 1; t <= n; t++) {
        int max_dist = 0;
        for(int x = 1; x <= k; x++) {
            int s = c[x];
            max_dist = max(max_dist, adj[s][t]+adj[t][s]);
        }
        if(min_max_dist > max_dist) {
            min_max_dist = max_dist;
            ans.clear();
            ans.push_back(t);
        }
        else if(min_max_dist == max_dist) {
            ans.push_back(t);
        }
    }
    
    for(int x : ans) 
        cout << x << ' ';
}