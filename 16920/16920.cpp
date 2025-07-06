#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
char board[1002][1002];
int S[10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
queue<pair<int,int>> Q[10];
int N, M, P;

int A[10];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for(int p = 1; p <= P; p++)
        cin >> S[p];

    char ch;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> ch;
            board[i][j] = ch;
            if(ch >= '1' && ch <= '9') {
                Q[ch - '0'].push({i,j});
            }
        }
    }

    while(1) {
        bool isExtend1 = 0;
        for(int p = 1; p <= P; p++) {
            for(int s = 0; s < S[p]; s++) {
                bool isExtend2 = 0;
                int qpsize = Q[p].size();
                while(qpsize--) {
                    pair<int,int> cur = Q[p].front(); Q[p].pop();
                    A[p]++;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(board[nx][ny] != '.') continue;
                        board[nx][ny] = board[cur.X][cur.Y];
                        Q[p].push({nx,ny});
                        isExtend1 = 1;
                        isExtend2 = 1;
                    }
                }
                if(!isExtend2) {
                    break;
                }
            }
        }
        if(!isExtend1) {
            break;
        }
    }
    for(int p = 1; p <= P; p++) {
        cout << A[p] << ' ';
    }
}