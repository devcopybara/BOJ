#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int used[10];

void permutation(int r) {
    if(r == m) {
        for(int i = 0; i < m; i++) 
            cout << arr[i] << ' '; 
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            arr[r] = i;
            used[i] = 1;
            permutation(r + 1);
            used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    permutation(0);
}