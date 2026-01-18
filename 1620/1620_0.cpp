#include <bits/stdc++.h>
using namespace std;
int n, m;
unordered_map<string,int> s2i;
string i2s[100'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s2i[s] = i;
        i2s[i] = s;
    }

    while(m--) {
        string s;
        cin >> s;
        if(isdigit(s[0]))
            cout << i2s[stoi(s)] << '\n';
        else
            cout << s2i[s] << '\n';
    }
}