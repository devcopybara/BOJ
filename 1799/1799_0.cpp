#include <bits/stdc++.h>
using namespace std;

int n;
bool board[10][10];
bool used[2][20]; // n - 1 + x - y : 0 ~ 18, x + y : 0 ~ 18

#define X first
#define Y second
int pCnt;
pair<int,int> pos[100];

int ans;
int cnt;
void func(int k) {
    if(k == pCnt) {
        ans = max(ans, cnt);
        return;
    }

    func(k + 1);
    
    auto cur = pos[k];
    if(!board[cur.X][cur.Y]) return;

    int diag1 = n - 1 + cur.X - cur.Y, diag2 = cur.X + cur.Y;
    if(used[0][diag1] || used[1][diag2]) return;

    cnt++;
    used[0][diag1] = used[1][diag2] = 1;
    func(k + 1);
    used[0][diag1] = used[1][diag2] = 0;
    cnt--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            pos[pCnt++] = {i,j};
        }
    }

    func(0);
    cout << ans;
}