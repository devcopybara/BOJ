// https://www.acmicpc.net/problem/2056
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second

const int MX = 10'005;
int dur[MX];

vector<int> adj[MX];
int deg[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq; // {종료시간, 정점번호}

    for(int i = 1; i <= n; i++) {
        cin >> dur[i];
        
        int m;
        cin >> m;
        deg[i] += m;
        while(m--) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
        
        if(deg[i] == 0) pq.push({dur[i],i});
    }

    int ans = 0;
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        ans = max(ans, cur.X);
        for(int nxtY : adj[cur.Y]) {
            deg[nxtY]--;
            if(deg[nxtY] == 0) pq.push({cur.X+dur[nxtY], nxtY});
        }
    }
    cout << ans;
}