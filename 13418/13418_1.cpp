// https://www.acmicpc.net/problem/13418
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

const int MX = 1'002;
int n, m;
vector<pii> adj[2][MX];
int chk[2][MX];
int cnt[2];
priority_queue<pii,vector<pii>,greater<pii>> pq[2];
int ans[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m; m++;
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;

        adj[0][a].push_back({!c,b});
        adj[0][b].push_back({!c,a});
        
        adj[1][a].push_back({c,b});
        adj[1][b].push_back({c,a});
    }

    // 최소값
    chk[0][0] = 1;
    for(auto [w,v] : adj[0][0]) {
        pq[0].push({w,v});
    }
    while(cnt[0] < n) {
        auto [w,v] = pq[0].top(); pq[0].pop();
        if(chk[0][v]) continue;
        chk[0][v] = 1;
        cnt[0]++;

        ans[0] += w;

        for(auto [nw,nv] : adj[0][v]) {
            if(chk[0][nv]) continue;
            pq[0].push({nw,nv});
        }
    }
    
    // 최대값
    chk[1][0] = 1;
    for(auto [w,v] : adj[1][0]) {
        pq[1].push({w,v});
    }
    while(cnt[1] < n) {
        auto [w,v] = pq[1].top(); pq[1].pop();
        if(chk[1][v]) continue;
        chk[1][v] = 1;
        cnt[1]++;

        ans[1] += w;

        for(auto [nw,nv] : adj[1][v]) {
            if(chk[1][nv]) continue;
            pq[1].push({nw,nv});
        }
    }

    cout << (n-ans[1])*(n-ans[1]) - ans[0]*ans[0];
}