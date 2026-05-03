#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
pair<int,int> line[1000005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        line[i] = {x,y};
    }
    sort(line,line+n);
    
    int ans = 0;
    pair<int,int> cur = line[0];
    for(int i = 1; i < n; i++) {
        pair<int,int> nxt = line[i];
        if(cur.Y < nxt.X) {
            ans += cur.Y - cur.X;
            cur = nxt;
        }
        else {
            if(cur.X > nxt.X)
                cur.X = nxt.X;
            if(cur.Y < nxt.Y)
                cur.Y = nxt.Y;
        }
    }
    ans += cur.Y - cur.X;
    cout << ans;
}