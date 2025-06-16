#include <bits/stdc++.h>
using namespace std;

const int MX = 2555;
int dat[2* MX + 1];
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

int front() {
    return dat[head];
}

int back() {
    return dat[tail-1];
}

int size() {
    return tail - head;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) push_back(i);

    int ans = 0;
    while(m--) {
        int tar;
        cin >> tar;

        int pos;
        for(int i = 0; i < size(); i++) {
            if(tar == dat[i + head]) {
                pos = i;
                break;
            }
        }

        if(pos <= size() - pos) {
            ans += pos;
            for(int i = 0; i < pos; i++) {
                push_back(front());
                pop_front();
            }
        }
        else {
            ans += size() - pos;
            for(int i = 0; i < size() - pos; i++) {
                push_front(back());
                pop_back();
            }
        }
        pop_front();
    }
    cout << ans;
}