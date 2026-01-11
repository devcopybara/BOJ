#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
int head, tail;

void push_back(int x) {
    dat[tail++] = x;
}

void pop_back() {
    tail--;
}

void pop_front() {
    head++;
}

int empty() {
    return head == tail;
}

int size() {
    return tail - head;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string x;
        cin >> x;

        head = tail = 0;
        
        if(n) {
            int cur = 0;
            for(int i = 1; i + 1 < x.size(); i++) {
                if(x[i] == ',') {
                    push_back(cur);
                    cur = 0;
                }
                else {
                    cur = 10 * cur + (x[i] - '0');
                }
            }
            push_back(cur);
        }


        int reversed = 0, errored = 0;
        for(char cmd : p) {
            if(cmd == 'R') {
                reversed ^= 1;
            }
            else { // if(cmd == 'D')
                if(empty()) {
                    errored = 1;
                    break;
                }
                if(reversed) pop_back();
                else pop_front();
            }
        }

        if(errored) cout << "error\n";
        else {
            cout << '[';
            int length = size();
            if(reversed) {
                for(int i = length - 1; i >= 0; i--)
                {
                    cout << dat[i + head];
                    if(i != 0) cout << ',';
                }
            }
            else {
                for(int i = 0; i < length; i++)
                {
                    cout << dat[i + head];
                    if(i != length - 1) cout << ',';
                }
            }
            cout << "]\n";
        }
    }
}