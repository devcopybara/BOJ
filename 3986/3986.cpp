#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
char dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    pos--;
}

int empty() {
    return pos == 0;
}

int top() {
    return dat[pos - 1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n;
    cin >> n;
    while(n--) {
        pos = 0;
        string s;
        cin >> s;

        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(empty() || top() != s[i])
                push(s[i]);
            else // if(top() == s[i])
                pop();
        }
        if(empty()) ans++;
    }
    cout << ans;
}