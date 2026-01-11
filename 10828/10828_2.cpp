#include <iostream>
using namespace std;

const int MX = 10'005;
int dat[MX];
int pos;

void push(int val) {
    dat[pos++] = val;
}

void pop() {
    --pos;
}

int size() {
    return pos;
}

int top() {
    return dat[pos-1];
}

int empty() {
    return (pos == 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if(cmd == "pop") {
            if(empty()) cout << "-1\n";
            else {
                cout << top() << '\n';
                pop();
            }
        }
        else if(cmd == "size") {
            cout << size() << '\n';
        }
        else if(cmd == "top") {
            if(empty()) cout << "-1\n";
            else cout << top() << '\n';
        }
        else { // if(cmd == "empty")
            cout << empty() << '\n';
        }
    }
}