#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

const int MX = 1520;
// lx, ly = 어떤 한 백조의 위치
int n, m, lx, ly, day = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qvis[MX][MX];
int lvis[MX][MX];
char board[MX][MX];
bool isPossible;
queue <pair<int, int>> q;
queue <pair<int, int>> lq;

bool OOB(int a, int b){
	return a < 0 || a >= n || b < 0 || b >= m;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char tmp;
			cin >> tmp;
			board[i][j] = tmp;
			if(tmp == 'L'){
				lx = i;
				ly = j;
			}
			if(tmp != 'X') {
				qvis[i][j] = 1;
				q.push({i, j});
			} 
				
		}
	}

	board[lx][ly] = '.';
	lvis[lx][ly] = 1;
	lq.push({lx, ly});

	while(!isPossible){
		day++;

		//얼음 녹이기
		int qsz = q.size();
		for(int i = 0; i < qsz; i++) {
			auto cur = q.front(); q.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(OOB(nx, ny)) continue;
				if(qvis[nx][ny]) continue;
				if(board[nx][ny] != 'X') continue;
				board[nx][ny] = '.';
				qvis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}

		//백조 찾기
		queue <pair<int, int>> nlq;
		while(!lq.empty()) {
			auto cur = lq.front(); lq.pop();
			for(int dir = 0; dir < 4; dir++){
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if(OOB(nx, ny) || lvis[nx][ny]) continue;
				if(board[nx][ny] == 'X'){
					lvis[nx][ny] = 1;
					nlq.push({nx, ny});
					continue;
				}
				else if(board[nx][ny] == 'L'){
					isPossible = true;
					break;
				}
				lvis[nx][ny] = 1;
				lq.push({nx, ny});
			}
		}
		lq = nlq;
	}
	cout << day;
}