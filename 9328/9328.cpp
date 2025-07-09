#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[102][102];
int vis[102][102];
queue<pair<int, int>> Q;
int t, n, m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--){
        queue<pair<int, int>> door[26];
		int key[26] = {};
		int ans = 0;
		cin >> n >> m;

		for(int i = 0; i < n + 2; i++){
			fill(vis[i], vis[i] + m + 2, 0);
			fill(board[i], board[i] + m + 2, 0);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin >> board[i][j];
            }
        }

        string keys;
		cin >> keys;
		for(char ch : keys) {
			key[ch - 'a'] = 1;
        }
		
		Q.push({0, 0});
		vis[0][0] = 1;
		while(!Q.empty()){
			pair<int,int> cur = Q.front(); Q.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1) continue;
				if(vis[nx][ny] || board[nx][ny] == '*') continue;

                vis[nx][ny] = 1;
				Q.push({nx, ny});
                
                if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                    int k = board[nx][ny] - 'a';
					key[k] = 1;
					while(!door[k].empty()){
                        pair<int,int> ndoor = door[k].front(); door[k].pop();
						Q.push({ndoor.X, ndoor.Y});
					}
				}
				else if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
                    int k = board[nx][ny] - 'A';
					if (!key[k]){ 
                        door[k].push({nx, ny});
						continue;
					}
				}
				else if(board[nx][ny] == '$') {
                    ans++;
                }
			}
		}
		cout << ans << "\n";
	}
}