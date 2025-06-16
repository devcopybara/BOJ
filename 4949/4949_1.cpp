#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(1) {
        getline(cin, s);
        if(s == ".") break;

        bool ans = true;
        stack<char> S;
        for(char ch : s) {
            if(ch == '(' || ch == '[') 
                S.push(ch);
            else if(ch == ')') {
                if(S.empty() || S.top() != '(') {
                    ans = false;
                    break;
                }
                S.pop();
            }
            else if(ch == ']') {
                if(S.empty() || S.top() != '[') {
                    ans = false;
                    break;
                }
                S.pop();
            }
        }
        if(!S.empty()) ans = false;
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
}