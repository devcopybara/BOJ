#include <bits/stdc++.h>
using namespace std;
int n;
int lc[100'005];
int rc[100'005];
int en;
int ans;

void inorder(int cur) {
    if(lc[cur]) inorder(lc[cur]);
    en = cur;
    if(rc[cur]) inorder(rc[cur]);
}

bool similar_inorder(int cur) {
    if(lc[cur]) {
        ans++;
        if(similar_inorder(lc[cur])) ans++;
        else return false;
    }
    if(rc[cur]) {
        ans++;
        if(similar_inorder(rc[cur])) ans++;
        else return false;
    }
    if(cur == en) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(b != -1) lc[a] = b;
        if(c != -1) rc[a] = c;
    }
    inorder(1);
    similar_inorder(1);
    cout << ans;
}