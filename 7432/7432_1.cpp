// https://www.acmicpc.net/problem/7432
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MX = 500 * 80 + 5;
map<string,int> nxt[MX];
const int ROOT = 1;
int unused = 2;

void insert(string& s) {
    int cur = ROOT;

    string dir;
    for(char c : s) {
        if(c != '\\') {
            dir += c;
        }
        else {
            if(nxt[cur][dir] == 0) nxt[cur][dir] = unused++;
            cur = nxt[cur][dir];
            dir.clear();
        }
    }
    if(nxt[cur][dir] == 0) nxt[cur][dir] = unused++;
    cur = nxt[cur][dir];
}

void print(int cur, int k) {
    for(auto a : nxt[cur]) {
        cout << string(k, ' ') << a.X << '\n';
        print(a.Y, k+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    while(n--) {
        string s; cin >> s;
        insert(s);
    }

    print(ROOT,0);
}