#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[52];
int dist[52];
int scores[52];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(1) {
        int u, v;
        cin >> u >> v;
        if(u == -1 || v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        int score = 0;
        fill(dist+1,dist+1+n,-1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            score = dist[cur];
            for(int nxt : adj[cur]) {
                if(dist[nxt] != -1) continue;
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
        scores[i] = score;
    }

    int min_score = 0x7f'ff'ff'ff;
    int min_count = 0;
    int candidates[52];
    for(int i = 1; i <= n; i++) {
        if(min_score > scores[i]) {
            min_score = scores[i];
            min_count = 1;
            candidates[min_count] = i;
        }
        else if(min_score == scores[i]) {
            candidates[++min_count] = i;
        }
    }

    cout << min_score << ' ' << min_count << '\n';
    for(int i = 1; i <= min_count; i++) 
        cout << candidates[i] << ' ';
}