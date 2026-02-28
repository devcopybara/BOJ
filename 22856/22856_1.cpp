#include <bits/stdc++.h>
using namespace std;

const int MX = 100'005;
int n;
int lc[MX];
int rc[MX];

int ans;
int mCnt;
int nCnt;

void inorder(int cur) {
    if(lc[cur] != -1) {
        mCnt++;
        inorder(lc[cur]);
        mCnt++;
    }

    nCnt++;
    if(nCnt == n) {
        ans = mCnt;
        return;
    }
    
    if(rc[cur] != -1) {
        mCnt++;
        inorder(rc[cur]);
        mCnt++;
    }

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
    }

    inorder(1);
    cout << ans;
}