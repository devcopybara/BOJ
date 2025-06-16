#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[--head] = x;
}

void push_back(int x) {
    dat[tail++] = x;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int size() {
    return tail - head;
}

int empty() {
    return tail == head;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s == "push_front") {
            int m;
            cin >> m;
            push_front(m);
        }
        else if(s == "push_back") {
            int m;
            cin >> m;
            push_back(m);
        }
        else if(s == "pop_front") {
            if(empty()) cout << "-1\n";
            else {
                cout << front() << '\n';
                pop_front();
            }
        }
        else if(s == "pop_back") {
            if(empty()) cout << "-1\n";
            else {
                cout << back() << '\n';
                pop_back();
            }
        }
        else if(s == "size") {
            cout << size() << '\n';
        }
        else if(s == "empty") {
            cout << empty() << '\n';
        }
        else if(s == "front") {
            if(empty()) cout << "-1\n";
            else cout << front() << '\n';
        }
        else if(s == "back") {
            if(empty()) cout << "-1\n";
            else cout << back() << '\n';
        }
    }
}