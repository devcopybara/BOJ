#include <bits/stdc++.h>
using namespace std;

int n;
int durability[300];
int weight[300];
int ans;
void func(int k, int cnt) {

    if(ans == n) return;
    
    if(cnt == n) {
        ans = n;
        return;
    }

    if(cnt == n - 1) {
        ans = n - 1;
        return;
    }

    if(k == n) {
        ans = max(ans, cnt);
        return;
    }

    if(durability[k] <= 0) {
        func(k + 1, cnt);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(i == k) continue;
        if(durability[i] <= 0) continue;
        
        durability[k] -= weight[i];
        durability[i] -= weight[k];
        func(k + 1, cnt + (durability[k] <= 0) + (durability[i] <= 0));
        durability[k] += weight[i];
        durability[i] += weight[k];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> durability[i] >> weight[i];

    func(0, 0);
    cout << ans;
}