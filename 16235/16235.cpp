// https://www.acmicpc.net/problem/16235

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int board[12][12];
vector<int> tree[12][12];
int s2d2[12][10];

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> s2d2[i][j];
            board[i][j] = 5;
        }
    }
            
    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    
    while(k--) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int k = tree[i][j].size() - 1;
                while(k >= 0) {
                    if(board[i][j] < tree[i][j][k]) break;
                    board[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                    k--;
                }

                for(int l = 0; l <= k; l++) {
                    board[i][j] += tree[i][j][l] / 2;
                }

                tree[i][j].erase(tree[i][j].begin(), tree[i][j].begin()+k+1);
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // fall
                for(int age : tree[i][j]) {
                    if(age % 5 == 0) {
                        for(int dir = 0; dir < 8; dir++)
                            tree[i + dx[dir]][j + dy[dir]].push_back(1);
                    }
                }
                // winter
                board[i][j] += s2d2[i][j];
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += tree[i][j].size();
    cout << ans;
}