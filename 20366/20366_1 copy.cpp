#include <bits/stdc++.h>
using namespace std;

const int MX = 605;
int a[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int ans = 1e9;

    for(int i = 0; i < n; i++) {
        for(int j = i + 3; j < n; j++) { // 최소 4개 필요
            int hi = a[i] + a[j];

            int st = i + 1;
            int en = j - 1;

            while(st < en) {
                int sum = a[st] + a[en];  
                ans = min(ans, abs(hi - sum));

                if(sum < hi) st++;
                else en--;
            }
        }
    }

    cout << ans;
}