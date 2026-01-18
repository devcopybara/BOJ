#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string,string> um;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1;
        s2 = to_string(i);
        um[s1] = s2;
        um[s2] = s1;
    }

    while(m--) {
        string s;
        cin >> s;
        cout << um[s] << '\n';
    }
}