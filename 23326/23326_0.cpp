// https://www.acmicpc.net/problem/23326
#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<bool> state(500'002,false);
set<int> landmark;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp) {
            landmark.insert(i);
            state[i] = 1;
        }
    }
    int cur = 1;
    while(q--) {
        int cmd,i,x;
        cin >> cmd;
        if(cmd == 1) {
            cin >> i;
            if(state[i]) {
                state[i] = 0;
                landmark.erase(i);
            }
            else {
                state[i] = 1;
                landmark.insert(i);
            }
        }
        else if(cmd == 2) {
            cin >> x;
            cur = (cur - 1 + x) % n + 1;
        }
        else {
            if(landmark.empty()) 
                cout << -1 << '\n';
            else {
                auto it = landmark.lower_bound(cur);
                if(it == landmark.end())
                    cout << *landmark.begin() + n - cur << '\n';
                else
                    cout << *it-cur << '\n';
            }
        }
    }
}