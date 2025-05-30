#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> L;
    for(int i = 1; i <= n; i++) L.push_back(i);
    
    cout << '<';
    while(!L.empty()) {
        for(int i = 0; i < k - 1; i++) {
            L.push_back(*L.begin());
            L.pop_front();
        }
        cout << *L.begin();
        L.pop_front();
    if (L.size()) cout << ", ";
  }
  cout << '>';
}