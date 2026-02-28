#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> child[52];
int root;
int d;
int ans;

void bfs() {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int isleaf = 1;
        int cur = q.front(); q.pop();
        for(int nxt : child[cur]) {
            if(nxt == d) continue;
            isleaf = 0;
            q.push(nxt);
        }
        ans += isleaf;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int p; 
        cin >> p;
        if(p == -1) root = i;
        else child[p].push_back(i);
    }

    cin >> d;
    if(root != d) bfs();
    cout << ans;
}