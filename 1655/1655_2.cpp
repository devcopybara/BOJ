#include <iostream>
using namespace std;

const int MX = 100'005;
typedef struct _priority_queue{
    int heap[MX];
    int sz = 0;
    bool (*cmp)(int, int);

    void init(bool (*f)(int, int)) {
        sz = 0;
        cmp = f;
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

    int size() {
        return sz;
    }
}priority_queue;

bool minheap_cmp(int a, int b) { return a < b; }
bool maxheap_cmp(int a, int b) { return a > b; }
priority_queue bigger_minheap;
priority_queue smaller_maxheap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bigger_minheap.init(minheap_cmp);
    smaller_maxheap.init(maxheap_cmp);

    int n;
    cin >> n;

    int x;
    cin >> x;
    smaller_maxheap.push(x);
    cout << x << '\n';
    while(--n) {
        cin >> x;

        if(smaller_maxheap.size() == bigger_minheap.size()) {
            if(x <= bigger_minheap.top()) {
                smaller_maxheap.push(x);
            }
            else {
                bigger_minheap.push(x);
                smaller_maxheap.push(bigger_minheap.top()); bigger_minheap.pop();
            }
        }
        else {
            if(x >= smaller_maxheap.top()) {
                bigger_minheap.push(x);
            }
            else {
                smaller_maxheap.push(x);
                bigger_minheap.push(smaller_maxheap.top()); smaller_maxheap.pop();
            }
        }
        
        cout << smaller_maxheap.top() << '\n';
    }
}