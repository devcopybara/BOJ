#include <bits/stdc++.h>
using namespace std;

int n;
bool board[10][10];
bool used[2][20]; // n - 1 + x - y : 0 ~ 18, x + y : 0 ~ 18

#define X first
#define Y second
int wCnt, bCnt;
pair<int,int> white_pos[50], black_pos[50];

int ans_white;
int cnt_white;
void func_white(int k) {
    if(k >= wCnt) {
        ans_white = max(ans_white, cnt_white);
        return;
    }

    func_white(k + 1);
    
    auto cur = white_pos[k];
    if(!board[cur.X][cur.Y]) return;

    int diag1 = n - 1 + cur.X - cur.Y, diag2 = cur.X + cur.Y;
    if(used[0][diag1] || used[1][diag2]) return;
    
    cnt_white++;
    used[0][diag1] = used[1][diag2] = 1;
    func_white(k + 1);
    used[0][diag1] = used[1][diag2] = 0;
    cnt_white--;
}

int ans_black;
int cnt_black;
void func_black(int k) {
    if(k >= bCnt) {
        ans_black = max(ans_black, cnt_black);
        return;
    }

    func_black(k + 1);
    
    auto cur = black_pos[k];
    if(!board[cur.X][cur.Y]) return;

    int diag1 = n - 1 + cur.X - cur.Y, diag2 = cur.X + cur.Y;
    if(used[0][diag1] || used[1][diag2]) return;

    cnt_black++;
    used[0][diag1] = used[1][diag2] = 1;
    func_black(k + 1);
    used[0][diag1] = used[1][diag2] = 0;
    cnt_black--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if((i + j) & 1) {
                black_pos[bCnt++] = {i,j};
            }
            else {
                white_pos[wCnt++] = {i, j};
            }
        }
    }
            
    func_white(0);
    func_black(0);
    cout << ans_white + ans_black;
}