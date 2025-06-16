#include <bits/stdc++.h>
using namespace std;

const int MX = 105;
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

    string s;
    while(1) {
        getline(cin, s);
        if(s == ".") break;

        bool ans = true;
        pos = 0;
        for(char ch : s) {
            if(ch == '(' || ch == '[') 
                push(ch);
            else if(ch == ')') {
                if(empty() || top() != '(') {
                    ans = false;
                    break;
                }
                pop();
            }
            else if(ch == ']') {
                if(empty() || top() != '[') {
                    ans = false;
                    break;
                }
                pop();
            }
        }
        if(!empty()) ans = false;
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }
}