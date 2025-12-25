#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string& s) {
    vector<int> f(s.size());

    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }

    return f;
}

string t, p;
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, t);
    getline(cin, p);

    vector<int> pos;

    vector<int> f = failure(p);
    int j = 0;
    for(int i = 0; i < t.size(); i++) {
        while(j > 0 && t[i] != p[j]) j = f[j-1];
        if(t[i] == p[j]) ++j;

        if(j == p.size()) {
            pos.push_back(i - p.size() + 1);
            j = f[j-1];
        }
    }
    
    cout << pos.size() << '\n';
    for(int x : pos) {
        cout << x + 1 << ' ';
    }
}