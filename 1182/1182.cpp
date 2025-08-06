#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
bool used[21];
int ans;

void subset(int k, int sum) {
    if(k == n) {
        if(s == sum) ans++;
        return;
    }
    subset(k + 1, sum);
    subset(k + 1, sum + arr[k]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    subset(0, 0);
    if(s == 0) ans--;
    cout << ans;
}