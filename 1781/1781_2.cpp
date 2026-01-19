// https://www.acmicpc.net/problem/1781
#include <iostream>
using namespace std;
using pii = pair<int,int>;

#define X first
#define Y second
const int MX = 200'005;
typedef struct _priority_queue{
    int heap[MX];
    int sz = 0;
    void push(int x) {
        heap[++sz] = x;
        int idx = sz;
        while(idx != 1) {
            int par = idx/2;
            if(heap[par] <= heap[idx]) break;
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
            if(rc <= sz && heap[rc] < heap[lc]) min_child = rc;
            if(heap[idx] <= heap[min_child]) break;
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
    bool empty() {
        return sz == 0;
    }
}priority_queue;
priority_queue pq;

pii arr[MX];
pii tmp[MX];
void MergeSort(int st, int en) {
    if(en <= st+1) return;
    int mid = (st+en)/2;
    MergeSort(st,mid);
    MergeSort(mid,en);

    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        if(lidx == mid) tmp[i] = arr[ridx++];
        else if(ridx == en) tmp[i] = arr[lidx++];
        else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    
    for(int i = 0; i < n; i++) {
        int d, c;
        cin >> d >> c;
        arr[i] = {d,c};
    }
    MergeSort(0,n);
    for(int i = 0; i < n; i++) {
        auto [d,c] = arr[i];

        pq.push(c);
        if(pq.size() > d) {
            pq.pop();
        }
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}