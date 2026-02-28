// https://www.acmicpc.net/problem/5214
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<int> h2s[MX];
vector<int> s2h[MX];
int dist[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    for(int h = 1; h <= m; h++) {
        for(int i = 0; i < k; i++) {
            int s;
            cin >> s;
            h2s[h].push_back(s);
            s2h[s].push_back(h);
        }
    }

    fill(dist,dist+1+n,-1);
    queue<int> q;
    dist[1] = 1;
    q.push(1);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int h : s2h[cur]) {
            for(int nxt : h2s[h]) {
                if(dist[nxt] != -1) continue;
                dist[nxt] = dist[cur]+1;
                q.push(nxt);
            }
        }
    }
    cout << dist[n];
}