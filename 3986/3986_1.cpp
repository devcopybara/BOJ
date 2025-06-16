#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n;
    cin >> n;
    while(n--) {
        stack<char> S;
        string s;
        cin >> s;

        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(S.empty() || S.top() != s[i])
                S.push(s[i]);
            else // if(S.top() == s[i])
                S.pop();
        }
        if(S.empty()) ans++;
    }
    cout << ans;
}