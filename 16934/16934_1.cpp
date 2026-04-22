#include <bits/stdc++.h>
using namespace std;

const int MX = 100000 * 10 + 5;
int nxt[MX][26];
unordered_map<string, int> x;
int ROOT = 1;
int unused = 2;
int c2i(char c) {
    return c - 'a';
}

void insert(string& s) {
    int cur = ROOT;
    for (auto c : s) {
        if (nxt[cur][c2i(c)] == 0)
            nxt[cur][c2i(c)] = unused++;
        cur = nxt[cur][c2i(c)];
    }
}

string find(string& s) {
    int cur = ROOT;
    string alias = "";
    for (auto c : s) {
        alias += c;
        if (nxt[cur][c2i(c)] == 0)
            return alias;
        else 
            cur = nxt[cur][c2i(c)];
    }
    // 마지막 글자까지 트라이에 존재한다면 닉네임+가입한 수가 별칭(단, 1은 생략)
    if (x[s] > 1) 
        alias += to_string(x[s]);
    return alias;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        x[s]++;
        cout << find(s) << '\n';
        insert(s);
    }
}