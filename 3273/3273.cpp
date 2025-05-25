#include <bits/stdc++.h>
using namespace std;

int occur[1000001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a;
    int minvalue = 1000000, maxvalue = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        occur[a]++;

        minvalue = min(minvalue, a);
        maxvalue = max(maxvalue, a);
    }

    int x;
    cin >> x;

    int ans = 0;
    int start = max(minvalue, x - 1000000), end = min(maxvalue + 1, (x + 1) / 2);
    for(int i = start; i < end; i++) {
        if(occur[i] && occur[x - i]) ans++;
    }
    cout << ans;
}