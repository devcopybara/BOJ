// https://www.acmicpc.net/problem/17619
#include <bits/stdc++.h>
using namespace std;
using ti3 = tuple<int,int,int>;

const int MX = 100'002;
int p[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q; cin >> n >> q;

    vector<ti3> v(n);
    for(int i = 0; i < n; i++) { 
        int x1, x2, y; cin >> x1 >> x2 >> y;
        v[i] = {x1,x2,i+1};
    }

    sort(v.begin(), v.end());

    int gCnt = 0;
    int mx = -1;
    for(int i = 0; i < n; i++) {
        auto [x1,x2,k] = v[i];
        if(x1 > mx) {
            p[k] = ++gCnt;
            mx = x2;
        }
        else {
            p[k] = gCnt;
            mx = max(mx, x2);
        }
    }

    while(q--) {
        int u,v; cin >> u >> v;
        cout << (p[u] == p[v]) << '\n';
    }
}