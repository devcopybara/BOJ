// https://www.acmicpc.net/problem/7785
#include <bits/stdc++.h>
using namespace std;

int n;
unordered_set<string> us;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if(log == "enter")
            us.insert(name);
        else
            us.erase(name);
    }

    vector<string> v(us.begin(),us.end());
    sort(v.begin(),v.end(),greater<string>());
    for(auto e : v) cout << e << '\n';
}