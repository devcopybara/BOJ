// https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>
using namespace std;

const int MX = 102;
int adj[MX][MX];
int ans[MX][MX];
int n;

bool vis[MX];
void bfs(int st) {
    queue<int> q;
    vis[st] = 1;
    q.push(st);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int nxt = 0; nxt < n; nxt++) {
            if(vis[nxt]) continue;
            if(!adj[cur][nxt]) continue;
            vis[nxt] = 1;
            q.push(nxt);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++) {
        fill(vis,vis+n,0);
        for(int j = 0; j < n; j++) { 
            if(adj[i][j]) bfs(j);
        }
        
        for(int j = 0; j < n; j++) ans[i][j] = vis[j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
}