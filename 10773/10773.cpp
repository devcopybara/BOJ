#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while(k--) {
        int n;
        cin >> n;
        
        if(n) {
            S.push(n);
        }
        else {
            S.pop();
        }
    }

    
    int ans = 0;    
    while(!S.empty()) {
        ans += S.top(); S.pop();
    }
    cout << ans;
}