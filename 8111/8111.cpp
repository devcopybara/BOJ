#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int MX = 20000;
bool vis[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        fill(vis, vis + n, 0);
        queue<pair<string,int>> Q;

        vis[1] = 1;
        Q.push({"1", 1 % n});

        bool isAnswer = false;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if(cur.Y == 0) {
                isAnswer = true;
                cout << cur.X << '\n';
                break;
            }

            if(cur.X.size() == 100) continue;

            // add 0
            int nr = (cur.Y * 10) % n;
            if(vis[nr] == 0) {
                vis[nr] = 1;
                Q.push({cur.X + "0", nr});
            }
            
            // add 1
            nr = (cur.Y * 10 + 1) % n;
            if(vis[nr] == 0) {
                vis[nr] = 1;
                Q.push({cur.X + "1", nr});
            }
        }
        if(!isAnswer) {
            cout << "BRAK\n";
        }
    }
}