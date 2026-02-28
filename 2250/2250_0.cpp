#include <bits/stdc++.h>
using namespace std;

int n;
int p[10'005];
int lc[10'005];
int rc[10'005];
int row[10'005];
int col[10'005];
int oCnt;

void inorder(int cur, int level) {
    col[cur] = level;
    if(lc[cur]) inorder(lc[cur], level+1);
    row[cur] = ++oCnt;
    if(rc[cur]) inorder(rc[cur], level+1);
}

int get_root() {
    int root = 1;
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) {
            root = i;
            break;
        }
    }
    return root;
}

void solve() {
    int root = get_root();

    inorder(root,1);

    int max_width = 1, min_level = 1;
    int min_cur_row = 0, max_cur_row = 0, cur_col = 0;

    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        if(cur_col != col[cur]) {
            if(max_width < max_cur_row - min_cur_row + 1) {
                max_width = max_cur_row - min_cur_row + 1;
                min_level = cur_col;
            }
            min_cur_row = row[cur];
            max_cur_row = row[cur];
            cur_col = col[cur];
        }
        min_cur_row = min(min_cur_row, row[cur]);
        max_cur_row = max(max_cur_row, row[cur]);

        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
    
    if(max_width < max_cur_row - min_cur_row + 1) {
        max_width = max_cur_row - min_cur_row + 1;
        min_level = cur_col;
    }

    cout << min_level << ' ' << max_width;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(b != -1) { lc[a] = b; p[b] = a; }
        if(c != -1) { rc[a] = c; p[c] = a; }
    }

    solve();
}