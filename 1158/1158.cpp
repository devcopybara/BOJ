#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    list<int> L;
    for(int i = 1; i <= n; i++) L.push_back(i);
    
    int cnt = k - 1;
    list<int>::iterator it = L.begin();
    
    cout << '<';
    while(!L.empty()) {
        
        if(cnt == 0) {
            cout << *it;
            
            cnt = k - 1;
            it = L.erase(it);
            
            if(!L.empty()) cout << ", ";
            else break;
            
            if(it == L.end()) it = L.begin();
        }
        else {
            cnt--;
            it++;
            if(it == L.end()) it = L.begin();
        }
    }
    cout << '>';
}