#include <bits/stdc++.h>
using namespace std;

stack<tuple<int,int,int>> S;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        int n;
        cin >> n;
        if(!n) break;
        
        long long ans = 0;
        
        int topX, topY, topW;
        for(int x = 1; x <= n; x++) {
            int y;
            cin >> y;

            while(!S.empty()) {
                tie(topX, topY, topW) = S.top();
                if(topY >= y) {
                    ans = max(ans, (long long)topY * (topW + x - 1 - topX));
                    S.pop();
                }
                else {
                    break;
                }
            }

            if(S.empty()) {
                ans = max(ans, (long long)y * x);
                S.push({x,y,x});
            }
            else {
                tie(topX, topY, topW) = S.top();
                ans = max(ans, (long long)y * (x - topX));
                S.push({x,y,(x - topX)});
            }
        }
        while(!S.empty()) {
            tie(topX, topY, topW) = S.top();
            ans = max(ans, (long long)topY * (topW + n - topX));
            S.pop();
        }
        cout << ans << '\n';
    }
}