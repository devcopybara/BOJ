#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
        
    int ans = 0, len = s.size();
    
    stack<pair<int, char>> S;
    for(int i = 0; i < len; i++) {
        if(s[i] == '(') {
            S.push({i, s[i]});
        }
        else { // if(c == ')')
            if(S.top().first == i - 1) ans += S.size() - 1;
            else ans += 1;
            S.pop();
        }
    }

    cout << ans;
}