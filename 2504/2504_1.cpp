#include <bits/stdc++.h>
using namespace std;

int isValid(string& s, int len) {
    stack<char> S;

    for(int i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == '[') {
            S.push(s[i]);
        }
        else if(!S.empty() 
            && ((s[i] == ')' && S.top() == '(') || (s[i] == ']' && S.top() == '['))
        ) {
            S.pop();
        }
        else {
            return 0;
        }
    }

    return S.empty() ? 1 : 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans, len = s.size();
    if(isValid(s, len)) {
        stack<pair<char, int>> S;
        for(int i = 0; i < len; i++) {
            if(s[i] == '(' || s[i] == '[')
                S.push({s[i], 0});
            else {
                int score = max(1, S.top().second), weight = s[i] == ')' ? 2 : 3;
                S.pop();
                
                if(S.empty()) ans += score * weight;
                else S.top().second += score * weight;
            }
        }
        cout << ans;
    }
    else {
        cout << 0;
    }
}