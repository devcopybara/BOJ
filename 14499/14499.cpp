// https://www.acmicpc.net/problem/14499
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int board[20][20];

int diceValue[6];
int diceMap[6] = {0, 1, 2, 3, 4, 5};
int n, m, x, y, k;

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void RollDice(int dir) {
    int nxtDiceMap[6];
    if(dir == 0) { // 동쪽
        int temp[6] = {diceMap[3], diceMap[1], diceMap[0], diceMap[5], diceMap[4], diceMap[2]};
        memcpy(nxtDiceMap, temp, sizeof(temp));
    }
    else if(dir == 1) { // 서쪽
        int temp[6] = {diceMap[2], diceMap[1], diceMap[5], diceMap[0], diceMap[4], diceMap[3]};
        memcpy(nxtDiceMap, temp, sizeof(temp));
    }
    else if(dir == 2) { // 북쪽
        int temp[6] = {diceMap[4], diceMap[0], diceMap[2], diceMap[3], diceMap[5], diceMap[1]};
        memcpy(nxtDiceMap, temp, sizeof(temp));
    }
    else if(dir == 3) { // 남쪽
        int temp[6] = {diceMap[1], diceMap[5], diceMap[2], diceMap[3], diceMap[0], diceMap[4]};
        memcpy(nxtDiceMap, temp, sizeof(temp));
    }
    memcpy(diceMap, nxtDiceMap, sizeof(nxtDiceMap));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> x >> y >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    while(k--) {
        int dir;
        cin >> dir;
        dir--;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(OOB(nx,ny)) continue;

        x = nx;
        y = ny;

        RollDice(dir);

        if(board[x][y] == 0) {
            board[x][y] = diceValue[diceMap[5]];
        }
        else {
            diceValue[diceMap[5]] = board[x][y];
            board[x][y] = 0;
        }

        cout << diceValue[diceMap[0]] << '\n';
    }
}