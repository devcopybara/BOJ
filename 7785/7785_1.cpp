// https://www.acmicpc.net/problem/7785
#include <bits/stdc++.h>
using namespace std;

int n;
set<string, greater<string>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if(log == "enter")
            s.insert(name);
        else
            s.erase(name);
    }

    for(auto e : s) cout << e << '\n';
}