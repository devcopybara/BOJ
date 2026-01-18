// https://www.acmicpc.net/problem/11286
#include <bits/stdc++.h>
using namespace std;

int heap[100'005];
int sz;

int cmp(int a, int b) {
    if(abs(a) < abs(b)) return 1;
    if(abs(a) == abs(b) && a < b) return 1;
    return 0;
}

void push(int x) {
    heap[++sz] = x;
    int idx = sz;
    while(idx != 1) {
        int par = idx / 2;
        if(cmp(heap[par],heap[idx])) break;
        swap(heap[par],heap[idx]);
        idx = par;
    }
}

int top() {
    return heap[1];
}

void pop() {
    swap(heap[1],heap[sz--]);
    int idx = 1;
    while(2*idx <= sz) {
        int lc = 2*idx, rc = 2*idx+1;
        int min_child = lc;
        if(rc <= sz && cmp(heap[rc],heap[lc]))
            min_child = rc;
        if(cmp(heap[idx],heap[min_child])) break;
        swap(heap[idx],heap[min_child]);
        idx = min_child;
    }
}

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        int c;
        cin >> c;
        if(c != 0) {
            push(c);
        }
        else {
            if(sz) {
                cout << top() << '\n';
                pop();
            }
            else {
                cout << "0\n";
            }
        }
    }
}