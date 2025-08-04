#include <bits/stdc++.h>
using namespace std;

int n;
bool used[15];
int col[15];
int ans;

bool check(int x, int y) {
    for(int row = 0; row < x; row++) {
        if(y - col[row] == x - row || 
            col[row] - y == x - row) {
            return true;
        }
    }
    return false;
}

void nqueen(int k) {
    if(k == n) {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i] && !check(k, i)) {
            col[k] = i;
            used[i] = 1;
            nqueen(k + 1);
            used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    nqueen(0);
    cout << ans;
}