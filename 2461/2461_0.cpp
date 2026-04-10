#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int,int>> v;

int cnt;
int freq[1'005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            v.push_back({tmp,i});
        }
    }
    sort(v.begin(), v.end());

    int ans = 1'000'000'000;

    int en = 0;
    for(int st = 0; st < n*m; st++) {
        while(en < n*m && cnt < n) {
            if(freq[v[en].Y] == 0) cnt++;
            freq[v[en].Y]++;
            en++;
        }

        if(cnt < n) break;
        ans = min(ans, v[en-1].X - v[st].X);
        freq[v[st].Y]--;
        if(freq[v[st].Y] == 0) cnt--;
    }

    cout << ans;
}