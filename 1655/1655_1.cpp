#include <bits/stdc++.h>
using namespace std;

priority_queue<int> smaller_maxheap;
priority_queue<int,vector<int>,greater<int>> bigger_minheap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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