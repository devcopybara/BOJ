#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    deque<int> DQ;
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push_front") {
            int m;
            cin >> m;
            DQ.push_front(m);
        }
        else if(s == "push_back") {
            int m;
            cin >> m;
            DQ.push_back(m);
        }
        else if(s == "pop_front") {
            if(DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if(s == "pop_back") {
            if(DQ.empty()) cout << "-1\n";
            else {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if(s == "size") {
            cout << DQ.size() << '\n';
        }
        else if(s == "empty") {
            cout << DQ.empty() << '\n';
        }
        else if(s == "front") {
            if(DQ.empty()) cout << "-1\n";
            else cout << DQ.front() << '\n';
        }
        else if(s == "back") {
            if(DQ.empty()) cout << "-1\n";
            else cout << DQ.back() << '\n';
        }
    }
}