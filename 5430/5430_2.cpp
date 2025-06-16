#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string p;
        int n;
        string x;
        cin >> p >> n >> x;
        
        deque<int> DQ;
        if(n) {
            int cur = 0;
            for(int i = 1; i + 1 < x.size(); i++) {
                if(x[i] == ',') {
                    DQ.push_back(cur);
                    cur = 0;
                }
                else {
                    cur = 10 * cur + (x[i] - '0');
                }
            }
            DQ.push_back(cur);
        }

        int reversed = 0, errored = 0;
        for(char cmd : p) {
            if(cmd == 'R') {
                reversed ^= 1;
            }
            else { // if(cmd == 'D')
                if(DQ.empty()) {
                    errored = 1;
                    break;
                }
                if(reversed) DQ.pop_back();
                else DQ.pop_front();
            }
        }

        if(errored) cout << "error\n";
        else {
            cout << '[';
            int length = DQ.size();
            if(reversed) reverse(DQ.begin(), DQ.end());
            for(int i = 0; i < length; i++)
            {
                cout << DQ[i];
                if(i != length - 1) cout << ',';
            }
            cout << "]\n";
        }
    }
}