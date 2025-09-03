#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

deque<pair<int, int>> dq;
int dir;

int n, k, l;
int board[100][100];

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    while(k--) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 1;
    }

    int ans = 0;
    
    dq.push_front({0,0});
    board[0][0] = 2;
    cin >> l;
    while(l--) {
        int t; char c;
        cin >> t >> c;

        while(ans < t) {
            ans++;
            
            pair<int,int> head = dq.front();
            int nx = head.X + dx[dir];
            int ny = head.Y + dy[dir];

            if(OOB(nx,ny) || board[nx][ny] == 2) {
                cout << ans;
                return 0;
            }

            if(board[nx][ny] == 0) {
                pair<int,int> rear = dq.back(); dq.pop_back();
                board[rear.X][rear.Y] = 0;
            }
            dq.push_front({nx,ny});
            board[nx][ny] = 2;
            
        }


        if(c == 'L') 
            dir = (dir + 3) % 4;
        else 
            dir = (dir + 1) % 4;
    }

    while(ans < 20000) {
        ans++;
        pair<int,int> head = dq.front();
        int nx = head.X + dx[dir];
        int ny = head.Y + dy[dir];
        if(OOB(nx,ny) || board[nx][ny] == 2) {
            cout << ans;
            return 0;
        }

        if(board[nx][ny] == 0) {
            pair<int,int> rear = dq.back(); dq.pop_back();
            board[rear.X][rear.Y] = 0;
        }
        dq.push_front({nx,ny});
        board[nx][ny] = 2;
    }
}