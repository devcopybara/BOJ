// https://www.acmicpc.net/problem/1256
#include <bits/stdc++.h>
using namespace std;
using uint16 = unsigned long long;
uint16 n, m, k;

char ans[205];
bool used[205];
void func(uint16 l, uint16 r) {
    if(k == 0) return;
    if(r == 0) {
        k--;
        if(k == 0) {
            for(uint16 i = 1; i <= n+m; i++)
                if(used[i])
                    ans[n+m-i] = 'z';
        }
        return;
    }

    for(uint16 i = r; i <= l; i++) {
        used[i] = 1;
        func(i - 1, r - 1);
        used[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(uint16 i = 0; i < n+m; i++) ans[i] = 'a';
    func(n+m, m);
    if(k == 0) cout << ans;
    else cout << -1; 
}