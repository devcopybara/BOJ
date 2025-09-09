// https://www.acmicpc.net/problem/15685
#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

bool coord[101][101];
bool vis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    queue<pair<int,int>> q;
    while(n--) {
        stack<int> s, ns;
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        coord[y][x] = 1;
        q.push({y,x});

        ns.push(d);
        x = x + dx[d], y = y + dy[d];
        coord[y][x] = 1;
        q.push({y,x});

        while(g--) {
            s = ns;
            while(!s.empty()) {
                d = (s.top() + 1) % 4; s.pop();
                ns.push(d);
                x = x + dx[d], y = y + dy[d];
                coord[y][x] = 1;
                q.push({y,x});
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(!coord[i][j]) continue;
            if(coord[i+1][j] && coord[i][j+1] && coord[i+1][j+1]) 
                ans++;
        }
    }
    cout << ans;
}