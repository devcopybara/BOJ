// https://www.acmicpc.net/problem/5052
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());

        bool ok = true;
        for(int i = 0; i < n-1; i++) {
            // v[i]가 v[i+1]의 prefix인지 확인
            if(v[i+1].compare(0, v[i].size(), v[i]) == 0) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}