// https://www.acmicpc.net/problem/1766
#include <bits/stdc++.h>
using namespace std;

const int MX = 32'005;
vector<int> adj[MX];
int deg[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }

    vector<int> res;
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) pq.push(i);
    }
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        res.push_back(cur);
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) pq.push(nxt);
        }
    }

    for(int x : res) cout << x << ' ';
}