#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> dat_t;
const int MX = 100005;
dat_t dat[MX];
int pos;

void push(dat_t x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

dat_t top() {
    return dat[pos - 1];
}

int size() {
    return pos;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
        
    int ans = 0, len = s.size();
    
    for(int i = 0; i < len; i++) {
        if(s[i] == '(') {
            push({i, s[i]});
        }
        else { // if(c == ')')
            if(top().first == i - 1) ans += size() - 1;
            else ans += 1;
            pop();
        }
    }

    cout << ans;
}