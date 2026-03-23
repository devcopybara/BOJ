#include <bits/stdc++.h>
using namespace std;

int board[2200][2200];
int ans[3]; // -1, 0, 1 결과 저장

// 해당 영역이 모두 같은 숫자면 그 숫자 반환, 섞여있으면 2 반환
int solve(int n, int r, int c) {
    if (n == 1) return board[r][c];

    int nn = n / 3;
    int counts[3][3];
    bool mixed = false;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            counts[i][j] = solve(nn, r + i * nn, c + j * nn);
            if (counts[i][j] == 2) mixed = true; // 자식 중 섞인 게 있음
        }
    }

    // 모든 자식이 같은 숫자고 섞이지 않았는지 확인
    int first = counts[0][0];
    if (!mixed) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (counts[i][j] != first) mixed = true;
            }
        }
    }

    if (!mixed) return first; // 모두 같으면 합쳐서 부모에게 보고

    // 섞여 있다면 각각을 정답에 추가
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (counts[i][j] != 2) ans[counts[i][j] + 1]++;
        }
    }
    return 2; // 나는 섞였다고 부모에게 보고
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> board[i][j];

    int res = solve(n, 0, 0);
    if (res != 2) ans[res + 1]++; // 전체가 하나인 경우 예외 처리

    for (int i = 0; i < 3; i++) cout << ans[i] << "\n";
}