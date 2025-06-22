#include <bits/stdc++.h>
using namespace std;

int choice[100005];
int n;
int state[100005]; 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        fill(state + 1, state + n + 1, 0);
        for(int i = 1; i <= n; i++) 
            cin >> choice[i];

        for(int i = 1; i <= n; i++) {
            if(state[i] == -1) continue;

            int curX = i;
            state[curX] = i;

            while(true) {
                int nx = choice[curX];
                
                if(state[nx] == i) {
                    while(state[nx] != -1) {
                        state[nx] = -1;
                        nx = choice[nx];
                    }
                    break;
                }
                else if(state[nx] != 0) {
                    break;
                }
                
                curX = nx;
                state[curX] = i;
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(state[i] != -1)
                ans++;
        cout << ans << '\n';
    }
}