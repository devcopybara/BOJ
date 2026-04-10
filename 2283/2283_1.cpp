// https://www.acmicpc.net/problem/2283

// A와 B 사이 길이 총합이 K

#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int,int>;

const int MX = 1'005;

pii interval[MX*2];
int ens[MX],cnts[MX];

int a, b;
bool solve(int mn, int mx) {
    int en = mn;
    for(int st = mn; st <= mx; st++) {

    }
    return false;
}

vector<pii> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, n2; cin >> n >> k; n2=n*2;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,-1});
        v.push_back({y,1});
    }
    sort(v.begin(),v.end());
    interval[0] = {v[0].X,0};

    int tot = 0;
    int en = 0;
    for(int st = 0; st < n2; st++) {
        while(en < n2 && tot < k) {
            interval[en+1].X = v[en].X;
            interval[en+1].Y = interval[en].Y + v[en].Y;
            tot += (interval[en+1].X-interval[en].X) * interval[en+1].Y;
            en++;
        }        

        if(tot < k) break;

        if(solve(st,en)) break;

        tot -= (interval[st+1].X-interval[st].X) * interval[st+1].Y;
    }

    cout << a << ' ' << b;
}