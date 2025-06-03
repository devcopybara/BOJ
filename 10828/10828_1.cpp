#include <bits/stdc++.h>
using namespace std;

stack<int> S;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    while(n--) {
        string s;
        int m;

        cin >> s;
        if(s == "push") {
            cin >> m;
            S.push(m);
        }
        else if(s == "pop") {
            if(S.empty()) cout << "-1\n";
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }
        else if(s == "size") cout << S.size() << '\n';
        else if(s == "empty") cout << S.empty() << '\n';
        else if(s == "top") {
            if(S.empty()) cout << "-1\n";
            else cout << S.top() << '\n';
        }
    }
}