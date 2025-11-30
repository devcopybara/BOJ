#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> child[52];
int root;
int d;
int ans;

void dfs(int cur) {
    int isleaf = 1;
    for(int nxt : child[cur]) {
        if(nxt == d) continue;
        isleaf = 0;
        dfs(nxt);
    }
    ans += isleaf;
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
    if(root != d) dfs(root);
    cout << ans;
}