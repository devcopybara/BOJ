#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    set<int> landmark;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x) landmark.insert(i);
    }

    int cur = 1;
    while(q--) {
        int query, x;
        cin >> query;
        switch(query) {
            case 1:
                cin >> x;
                if(landmark.find(x) == landmark.end()) landmark.insert(x);
                else landmark.erase(x);
                break;
            case 2:
                cin >> x;
                cur = (cur - 1 + x) % n + 1;
                break;
            case 3:
            default:
                if(landmark.empty()) 
                    cout << "-1\n";
                else {
                    auto it = landmark.lower_bound(cur);
                    if(it == landmark.end())
                        cout << *landmark.begin() + n - cur << '\n';
                    else
                        cout << *it-cur << '\n';
                }
                break;
        }
    }
}