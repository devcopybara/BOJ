#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;

        int cnt = 0;
        int len = s.size();
        for(int i = 0; i < len && cnt >= 0; i++) {
            if(s[i] == '(') cnt++;
            else cnt--;
        }

        if(cnt == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}