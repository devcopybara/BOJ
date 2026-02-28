#include <bits/stdc++.h>
using namespace std;

const int MX = 10'005;
int n;
int p[MX];
int lc[MX];
int rc[MX];

int col[MX];
int cCnt;
void inorder(int cur) {
    if(lc[cur] != -1) inorder(lc[cur]);
    col[cur] = ++cCnt;
    if(rc[cur] != -1) inorder(rc[cur]);
}

int max_row, max_weight;
void bfs(int root) {
    queue<int> q;
    q.push(root);

    int rCnt = 0;
    while(!q.empty()) {
        rCnt++;
        int min_col = MX;
        int max_col = 0;

        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            int cur = q.front(); q.pop();
            min_col = min(min_col, col[cur]);
            max_col = max(max_col, col[cur]);
            if(lc[cur] != -1) q.push(lc[cur]);
            if(rc[cur] != -1) q.push(rc[cur]);
        }

        if(max_weight < max_col - min_col + 1) {
            max_weight = max_col - min_col + 1;
            max_row = rCnt;
        }
    }
}

int get_root() {
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) {
            return i;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;

        p[b] = a;
        p[c] = a;
    }

    int root = get_root();
    inorder(root);
    bfs(root);
    cout << max_row << ' ' << max_weight;
}