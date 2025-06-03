#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[MX];
int head, tail;
void push(int x) {
    dat[tail++] = x;
}
void pop() {
    head++;
}
int size() {
    return tail - head;
}
int empty() {
    return head == tail;
}
int back() {
    return dat[tail-1];
}
int front() {
    return dat[head];
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push") {
            int m;
            cin >> m;
            push(m);
        }
        else if(s == "pop") {
            if(empty()) cout << "-1\n";
            else {
                cout << front() << '\n';
                pop();
            }
        }
        else if(s == "size") cout << size() << '\n';
        else if(s == "empty") cout << empty() << '\n';
        else if(s == "back") {
            if(empty()) cout << "-1\n";
            else cout << back() << '\n';
        }
        else if(s == "front") {
            if(empty()) cout << "-1\n";
            else cout << front() << '\n';
        }
    }
}