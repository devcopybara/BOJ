#include <bits/stdc++.h>
using namespace std;
int n;
int idx[1000005];
int val[1000005];
int cnt[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        val[i] = v;
        idx[v] = i;
    }
    fill(cnt + 1, cnt + n + 1, 1);

    int max_cnt = 0;
    for(int i = 1; i <= n; i++) {
        int v = val[i];
        if(idx[v-1] < i) {
            cnt[v] = cnt[v-1] + 1;
            max_cnt = max(max_cnt, cnt[v]);
        }
    }
    cout << n - max_cnt;
}