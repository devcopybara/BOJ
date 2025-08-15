#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, m;
int board[50][50];
vector<pair<int,int>> home;
int hCnt;
vector<pair<int,int>> chicken;
int cCnt;
int ans = 5000;
int cnt;
bool used[13];
void func(int k) {
    if(cnt == m) {
        int tot = 0;
        for(int i = 0; i < hCnt; i++) {
            int dst = 50;
            for(int j = 0; j < cCnt; j++) {
                if(used[j]) {
                    dst = min(dst, abs(chicken[j].X-home[i].X)+abs(chicken[j].Y-home[i].Y));
                }
            }
            tot += dst;
        }
        ans = min(ans, tot);
        return;
    }

    if(k == cCnt) {
        return;
    }
    
    cnt++;
    used[k] = 1;
    func(k + 1);
    used[k] = 0;
    cnt--;

    func(k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
            if(tmp == 1) home.push_back({i,j});
            else if(tmp == 2) chicken.push_back({i,j});
        }
    }

    hCnt = home.size();
    cCnt = chicken.size();
    func(0);
    cout << ans;
}