#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> Q;
    for(int i = 1; i <= n; i++) Q.push(i);

    int ord = 0;
    while(Q.size() > 1) {
        if(ord) Q.push(Q.front());
        Q.pop();
        ord ^= 1;
    }
    cout << Q.front() << '\n';
}