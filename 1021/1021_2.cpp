#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uint64;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) DQ.push_back(i);

    int ans = 0;
    while(m--) {
        int tar;
        cin >> tar;

        uint64 pos = find(DQ.begin(), DQ.end(), tar) - DQ.begin();

        if(pos <= DQ.size() - pos) {
            for(uint64 i = 0; i < pos; i++) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            ans += pos;
        }
        else {
            for(uint64 i = 0; i < DQ.size() - pos; i++) {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans += DQ.size() - pos;
        }
        DQ.pop_front();
    }
    cout << ans;
}