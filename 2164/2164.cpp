#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
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

    for(int i = 1; i <= n; i++) push(i);

    int ord = 0;
    while(size() > 1) {
        if(ord) push(front());
        pop();
        ord ^= 1;
    }
    cout << front() << '\n';
}