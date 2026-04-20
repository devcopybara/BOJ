#include <bits/stdc++.h>
using namespace std;

int n, k;
int coin[15];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    int ans = 0;
    for(int i = n; i > 0; i--) {
        while(k >= coin[i]) {
            k -= coin[i];
            ans++;
        }
    }
    cout << ans;
}