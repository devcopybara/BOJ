#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
using pii = pair<int,int>;
const int MX = 1'005;
int n, m;
vector<pii> adj[MX];
priority_queue<pii, vector<pii>, greater<pii>> min_heap;
priority_queue<pii> max_heap;
bool chk[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < m+1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({!c,b});
        adj[b].push_back({!c,a});
    }

    int min_ans = 0;
    int cnt = 0;

    chk[0] = true;
    for(auto nxt : adj[0])
        min_heap.push(nxt);

    while(cnt < n) {
        auto cur = min_heap.top(); min_heap.pop();
        int cost = cur.X;
        int u = cur.Y;

        if(chk[u]) continue;
        chk[u] = true;
        min_ans += cost;
        cnt++;

        for(auto nxt : adj[u])
            if(!chk[nxt.Y]) 
                min_heap.push(nxt);
    }

    fill(chk,chk+n+1,false);
    int max_ans = 0;
    cnt = 0;

    chk[0] = true;
    for(auto nxt : adj[0])
        max_heap.push(nxt);

    while(cnt < n) {
        auto cur = max_heap.top(); max_heap.pop();
        int cost = cur.X;
        int u = cur.Y;

        if(chk[u]) continue;
        chk[u] = true;
        max_ans += cost;
        cnt++;

        for(auto nxt : adj[u])
            if(!chk[nxt.Y]) 
                max_heap.push(nxt);
    }

    cout << max_ans*max_ans - min_ans*min_ans;
}