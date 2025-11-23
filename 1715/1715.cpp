// https://www.acmicpc.net/problem/1715
#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> heap;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
    }

    int ans = 0;
    while(heap.size() >= 2) {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        ans += a+b;
        heap.push(a+b);
    }
    cout << ans;
}