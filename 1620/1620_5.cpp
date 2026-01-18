#include <iostream>
using namespace std;

const int M = 1'000'003;
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
typedef struct _unordered_map{
    int status[M]; // EMPTY / OCCUPY / DUMMY
    string key[M];
    int val[M];
    int unused = 0;

    const int a = 1000;
    int my_hash(string& s){
        int h = 0;
        for(auto x : s)
            h = (h * a + x) % M;
        return h;
    }

    void init() {
        fill(status, status+M, -1);
    }

    int find(string k) {
        int idx = my_hash(k);
        while(status[idx] != EMPTY) {
            if(status[idx] == OCCUPY && key[idx] == k) return idx;
            idx = (idx+1) % M;
        }
        return -1;
    }

    void insert(string k, int v) {
        int idx = my_hash(k);
        while(status[idx] == OCCUPY) {
            if(key[idx] == k) {
                val[idx] = v;
                return;
            }
            idx = (idx+1) % M;
        }

        status[idx] = OCCUPY;
        key[idx] = k;
        val[idx] = v;
    }

    void erase(string k) {
        int idx = find(k);
        if(idx != -1) status[idx] = DUMMY;
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