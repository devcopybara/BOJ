#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 100;
    cout << n << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || i == n || j == n) cout << "0 ";
            else cout << "1 "; 
        }
        cout << '\n';
    }
}