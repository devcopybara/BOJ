// https://www.acmicpc.net/problem/14500
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board[500][500];
vector<vector<pair<int,int>>> tetros;

pair<int,int> pos[16];
int arr[4];

bool isAdj(pair<int,int> a, pair<int,int> b) {
    if(a.X == b.X) return abs(a.Y - b.Y) == 1;
    if(a.Y == b.Y) return abs(a.X - b.X) == 1;
    return false;
}

bool isTetro(vector<pair<int,int>> tetro) {
    bool conn = false;
    for(int i = 0; i < 4; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(isAdj(tetro[i], tetro[j])) cnt++;    
        }
        if(cnt == 0) return false;
        if(cnt >= 2) conn = true;
    }
    return conn;
}

void check() {
    vector<pair<int,int>> tetro;
    for(int i = 0; i < 4; i++)
        tetro.push_back(pos[arr[i]]);
    if(isTetro(tetro)) tetros.push_back(tetro);
}

void func(int k) {
    if(k == 4) {
        check();
        return;
    }

    int s = k == 0 ? 0 : arr[k-1] + 1;
    for(int i = s; i < 16; i++) {
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    // set tetros
    for(int i = 0; i < 16; i++)
        pos[i] = { i/4, i%4 };
    func(0);

    // chk tetros
    int ans = 0;
    for(int i = 0; i <= n-4; i++) {
        for(int j = 0; j <= m-4; j++) {
            for(vector<pair<int,int>> tetro : tetros) {
                int tot = 0;
                for(pair<int,int> poly : tetro) {
                    tot += board[i+poly.X][j+poly.Y];
                }
                ans = max(ans, tot);
            }
        }
    }
    cout << ans;
}