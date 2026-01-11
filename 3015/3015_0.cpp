#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
stack<pair<int,int>> S;

const int MX = 500002;
int y[MX];

int cnt[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }

    long long ans = 0;
    for(int x = n - 1; x >= 0; x--) {
        while(!S.empty() && S.top().Y < y[x]) {
            S.pop();
            ans++;
        }
        if(!S.empty()) {
            if(S.top().Y == y[x]) {
                cnt[x] = cnt[S.top().X] + 1;
                ans += cnt[x];
            }
            else {
                cnt[x] = 1;
                ans++;
            }
        }

        S.push({x, y[x]});
    }
    cout << ans;
}