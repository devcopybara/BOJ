// https://www.acmicpc.net/problem/17281
#include <bits/stdc++.h>
using namespace std;

int n;
int ability[50][9];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> ability[i][j];
        }
    }
    int ans = 0;
    
    vector<int> order8(8); iota(order8.begin(), order8.end(), 1);
    do {
        vector<int> order9 = order8; order9.insert(order9.begin()+3,0);
        int tot = 0;
        for(int i = 0, j = 0; i < n; i++) {
            queue<int> base; for(int i = 0; i < 3; i++) base.push(0);
            int cnt = 0;
            while(cnt < 3) {
                if(ability[i][order9[j]]) {
                    tot += base.front(); base.pop();
                    base.push(1);
                    for(int k = 1; k < ability[i][order9[j]]; k++) {
                        tot += base.front(); base.pop();
                        base.push(0);
                    }
                }
                else {
                    cnt++;
                }
                j = (j + 1) % 9;
            }
        }
        ans = max(ans, tot);
    } while(next_permutation(order8.begin(), order8.end()));
    cout << ans;
}