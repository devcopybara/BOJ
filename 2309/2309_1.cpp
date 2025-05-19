#include <bits/stdc++.h>

using namespace std;

int arr[9];
int ans[7];
int used[9];
int ret;

void dfs(int d, int sum, int s) {
    if(ret == 1) return;

    if(9 - s < 7 - d) return;

    if(d == 7) {
        if(sum == 100) {
            ret = 1;
            return;
        }
    }

    if(sum >= 100) return;

    if(sum + arr[s] * (7 - d) > 100) return;

    for(int i = s; i < 9; i++) {
        if(used[i] == 0) {
            used[i] = 1;
            ans[d] = arr[i];
            dfs(d + 1, sum + arr[i], i + 1);
            if(ret == 1) return;
            used[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);   

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + 9);

    dfs(0, 0, 0);

    for(int i = 0; i < 7; i++) {
        cout << ans[i] << "\n"; 
    }
}