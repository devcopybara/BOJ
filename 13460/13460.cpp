// https://www.acmicpc.net/problem/13460
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n, m;
char board[10][10];
bool vis[10][10][10][10];

pair<int,int> r, b, o;
queue<tuple<pair<int,int>,pair<int,int>,int>> Q;

pair<int,int> move1(pair<int,int> cur, int dir) {
    while(1) {
        pair<int,int> nxt = {cur.X + dx[dir], cur.Y + dy[dir]};
        if(nxt == o) {
            cur = nxt;
            break;
        }
        if(board[nxt.X][nxt.Y] == '#') break;
        cur = nxt;
    }
    return cur;
}
pair<int,int> move2(pair<int,int> cur, pair<int,int> pre, int dir) {
    while(1) {
        pair<int,int> nxt = {cur.X + dx[dir], cur.Y + dy[dir]};
        if(nxt == o) {
            cur = nxt;
            break;
        }
        if(board[nxt.X][nxt.Y] == '#' || nxt == pre) break;
        cur = nxt;
    }
    return cur;
}

pair<pair<int,int>,pair<int,int>> move(pair<int,int> r, pair<int,int> b, int dir) {
    bool priority;
    pair<int,int> f, s, nf, ns;
    if(r.X * dx[dir] + r.Y * dy[dir] > b.X * dx[dir] + b.Y * dy[dir]) {
        f = r, s = b;
        priority = 1;
    }
    else {
        f = b, s = r;
        priority = 0;
    }
        
    f = move1(f,dir);
    s = move2(s,f,dir);
    
    if(priority) return {f,s};
    return {s,f};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            if(tmp == 'R') {
                r = {i,j};
                board[i][j] = '.';
            }
            else if(tmp == 'B') {
                b = {i,j};
                board[i][j] = '.';
            }
            else {
                if(tmp == 'O') o = {i,j};
                board[i][j] = tmp;
            }
        }
    }

    vis[r.X][r.Y][b.X][b.Y] = 1;
    Q.push({r,b,0});
    while(!Q.empty()) {
        int d;
        tie(r,b,d) = Q.front(); Q.pop();
        if(d == 10) {
            cout << -1;
            return 0;
        }
        //cout << r.X << "," << r.Y << " " << b.X << "," << b.Y << " " << d << '\n';
        for(int dir = 0; dir < 4; dir++) {
            pair<int,int> nr, nb;
            tie(nr,nb) = move(r, b, dir);
            
            if(nb == o) continue;
            if(nr == o) {
                cout << d + 1;
                return 0;
            }
            if(vis[nr.X][nr.Y][nb.X][nb.Y]) continue;

            vis[nr.X][nr.Y][nb.X][nb.Y] = 1;
            Q.push({nr,nb,d+1});
        }
    }
    cout << -1;
    return 0;
}