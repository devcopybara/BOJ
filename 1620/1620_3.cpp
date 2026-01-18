#include <iostream>
using namespace std;

const int M = 100'001;
const int MX = 100'001;
typedef struct _unordered_map{
    int head[M];
    int pre[MX];
    int nxt[MX];
    string key[MX];
    int val[MX];
    int unused = 0;

    const int a = 1000;
    int my_hash(string& s){
        int h = 0;
        for(auto x : s)
            h = (h * a + x) % M;
        return h;
    }

    void init() {
        fill(head, head+M, -1);
        fill(pre, pre+MX, -1);
        fill(nxt, nxt+MX, -1);
    }

    int find(string k) {
        int h = my_hash(k);
        
        int idx = head[h];
        while(idx != -1) {
            if(key[idx] == k) return idx;
            idx = nxt[idx];
        }
        return -1;
    }

    void insert(string k, int v) {
        int h = my_hash(k);

        key[unused] = k;
        val[unused] = v;
        nxt[unused] = head[h];
        if(head[h] != -1) pre[head[h]] = unused;

        head[h] = unused;
        unused++;
    }
}unordered_map;

unordered_map s2i;
string i2s[100'005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    s2i.init();

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s2i.insert(s, i);
        i2s[i] = s;
    }

    while(m--) {
        string s;
        cin >> s;
        if(isdigit(s[0]))
            cout << i2s[stoi(s)] << '\n';
        else
            cout << s2i.val[s2i.find(s)] << '\n';
    }
}