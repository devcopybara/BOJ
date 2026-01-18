// https://www.acmicpc.net/problem/11286
#include <iostream>
using namespace std;

const int MX = 100'005;
typedef struct _priority_queue{
    int heap[MX];
    int sz = 0;

    bool cmp(int a, int b) {
        if(abs(a) != abs(b)) return abs(a) < abs(b);
        return a < 0 && b > 0;
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

    void pop() {
        swap(heap[1],heap[sz--]);
        int idx = 1;
        while(2*idx <= sz) {
            int lc = 2*idx, rc = 2*idx+1;
            int min_child = lc;
            if(rc <= sz && cmp(heap[rc],heap[lc])) min_child = rc;

            if(cmp(heap[idx],heap[min_child])) break;
            swap(heap[idx],heap[min_child]);
            idx = min_child;
        }
    }

    int top() {
        return heap[1];
    }

    bool empty() {
        return sz == 0;
    }
}priority_queue;
priority_queue pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;

        if(x == 0) {
            if(pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}