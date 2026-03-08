// https://www.acmicpc.net/problem/1197
#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
vector<pair<int,int>> adj[MX]; // {비용, 정점 번호}
bool chk[MX]; // chk[i] : i번째 정점이 최소 신장 트리에 속해있는가?
int cnt = 0; // 현재 선택된 간선의 수
priority_queue<tuple<int,int,int>, // {비용, 정점1, 정점2}
                vector<tuple<int,int,int>>, 
                greater<tuple<int,int,int>>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v,e;
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    chk[1] = 1;
    for(auto [w,v] : adj[1]) {
        pq.push({w,1,v});
    }
        
    int ans = 0;
    while(cnt < v-1) {
        auto [curW,curU,curV] = pq.top(); pq.pop();
        if(chk[curV]) continue;
        chk[curV] = 1;
        cnt++;
        ans += curW;
        for(auto [nxtW,nxtV] : adj[curV]) {
            if(!chk[nxtV]) {
                pq.push({nxtW,curV,nxtV});
            }
        }
            
    }
    cout << ans;
}