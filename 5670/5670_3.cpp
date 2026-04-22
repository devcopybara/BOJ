// https://www.acmicpc.net/problem/5670
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

const int MX = 1e5 * 81 + 5;
bool chk[MX];
vector<pair<char,int>> nxt[MX];
int cnt[MX];
const int ROOT = 1;
int unused = ROOT+1;

unsigned int c2i(int cur, char c) {
    unsigned int sz = nxt[cur].size();
    for(unsigned int i = 0; i < sz; i++) {
        if(nxt[cur][i].X == c) return i;
    }
    return sz;
}

void insert(string& s) {
    int cur = ROOT;
    for(char c : s) {

        bool isused = false;
        int k = nxt[cur].size();
        for(int i = 0; i < k; i++) {
            if(nxt[cur][i].X == c) {
                isused = true;
                k = i;
                break;
            }
        }

        if(!isused) {nxt[cur].push_back({c,unused++}); cnt[cur]++;}
        cur = nxt[cur][k].Y;
    }
    chk[cur] = 1;
}

int find(string& s) {
    int ret = 1;

    int k = nxt[ROOT].size();
    for(int i = 0; i < k; i++) {
        if(nxt[ROOT][i].X == s[0]) {
            k = i;
            break;
        }
    }
    int cur = nxt[ROOT][k].Y; 
    
    int len = s.length();
    for(int i = 1; i < len; i++) {
        if(cnt[cur] > 1 || (cnt[cur] == 1 && chk[cur])) ret++;

        int k = nxt[cur].size();
        for(int i = 0; i < k; i++) {
            if(nxt[cur][i].X == s[i]) {
                k = i;
                break;
            }
        }
        cur = nxt[cur][k].Y;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n) {
        unused = ROOT+1;

        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            insert(v[i]);
        }

        double ans = 0;
        for(string s : v) {
            ans += find(s);
        }

        cout << fixed  << setprecision(2) << ans / n << '\n';
        
        for(int i = 1; i < unused; i++) nxt[i].clear();
        fill(cnt+1,cnt+unused,0);
    }
}