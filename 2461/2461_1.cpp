// https://www.acmicpc.net/problem/2461

// 대표들 능력치 최대최소값 차이 최소값

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int,int>;

const int MX = 1'005;
int a[MX][MX];
int idx[MX];

priority_queue<pii,vector<pii>,greater<pii>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

    int mxi = 0;
    for(int i = 0; i < n; i++) {
        sort(a[i],a[i]+m);
        pq.push({a[i][0],i});
        if(a[mxi][0] < a[i][0]) mxi = i;
    }

    int ans = 1e9;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int mxv = a[mxi][idx[mxi]], mnv = cur.X, mni = cur.Y;

        ans = min(ans, mxv - mnv);
        
        idx[mni]++;
        if(idx[mni] == m) break;
        mnv = a[mni][idx[mni]];
        
        pq.push({mnv, mni});
        if(mxv < mnv) mxi = mni;
    }

    cout << ans;
}