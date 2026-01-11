#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    --pos;
}

int size() {
    return pos;
}

int empty() {
    return pos == 0;
}

int top() {
    return dat[pos-1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    while(n--) {
        string s;
        int m;

        cin >> s;
        if(s == "push") {
            cin >> m;
            push(m);
        }
        else if(s == "pop") {
            if(empty()) cout << "-1\n";
            else {
                cout << top() << '\n';
                pop();
            }
        }
        else if(s == "size") cout << size() << '\n';
        else if(s == "empty") cout << empty() << '\n';
        else if(s == "top") {
            if(empty()) cout << "-1\n";
            else cout << top() << '\n';
        }
    }
}