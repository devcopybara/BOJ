#include <bits/stdc++.h>
using namespace std;
int t,k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        multiset<int> pq;
        cin >> k;
        while(k--) {
            char cmd;
            int val;
            cin >> cmd >> val;
            if(cmd == 'I') {
                pq.insert(val);
            }
            else if(pq.size() > 0) {
                if(val == -1)
                    pq.erase(pq.begin());
                else
                    pq.erase(prev(pq.end()));
            }
        }
        if(pq.size() > 0) 
            cout << *prev(pq.end()) << ' ' << *pq.begin() << '\n';
        else 
            cout << "EMPTY\n";
    }
}