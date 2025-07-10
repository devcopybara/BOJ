#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int sCnt;
char ans[200002];
int aCnt;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    S.push(sCnt++);

    while(n--) {
        int m;
        cin >> m;
        
        while(m > S.top()) {
            S.push(sCnt++);
            ans[aCnt++] = '+';
        }

        if(m == S.top()) {
            S.pop();
            ans[aCnt++] = '-';
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < aCnt; i++) {
        cout << ans[i] << '\n';
    }
}