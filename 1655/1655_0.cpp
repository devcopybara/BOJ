// https://www.acmicpc.net/problem/1655
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> lhq;
priority_queue<int,vector<int>,greater<int>> uhq;
int n;
int x;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> x;
    lhq.push(x);
    cout << x << '\n';

    while(--n) {
        cin >> x;
        if(x <= lhq.top())
            lhq.push(x);
        else
            uhq.push(x);                

        if(lhq.size() < uhq.size()) {
            lhq.push(uhq.top()); uhq.pop();
        }
        else if(lhq.size() >= uhq.size() + 2) {
            uhq.push(lhq.top()); lhq.pop();
        }

        cout << lhq.top() << '\n';
    }
}