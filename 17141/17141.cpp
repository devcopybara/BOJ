// https://www.acmicpc.net/problem/17141

// time complex : 
// [바이러스 m개 선택] x ([vis 초기화] + [bfs 탐색] + [빈칸 탐색])
// [10C5] x ([10 X 10] + [10 X 10 X 4] + [10 X 10])
// 151,200 < 500,000,000

// Optimization : 
// [bfs 탐색] OOB 제거 
// [빈칸 탐색] 제거

#include <bits/stdc++.h>
using namespace std;

#define INF 5000 // 0x7fffffff

#define X first
#define Y second
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int n,m;
int board[50][50];
int vis[50][50];

vector<pair<int,int>> virus;

bool OOB(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 2)
                virus.push_back({i,j});
            else
                board[i][j] = tmp;
        }
    }

    int ans = INF;

    queue<pair<int,int>> q;
    
    int size = virus.size();
    vector<int> brute(size);
    fill(brute.begin() + size - m, brute.end(), 1);
    do{
        for(int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, -1);

        for(int i = 0; i < size; i++) {
            if(brute[i] == 1) {
                vis[virus[i].X][virus[i].Y] = 0;
                q.push(virus[i]);
            }
        }

        int time = 0;

        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            time = vis[cur.X][cur.Y];
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(OOB(nx,ny) || vis[nx][ny] != -1 || board[nx][ny]) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                q.push({nx,ny});
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0 && vis[i][j] == -1) {
                    time = INF;
                    break;
                }
            }
        }

        ans = min(ans, time);
    }while(next_permutation(brute.begin(), brute.end()));

    cout << (ans == INF ? -1 : ans);
}