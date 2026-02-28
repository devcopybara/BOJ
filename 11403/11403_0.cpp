// https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>
using namespace std;

const int MX = 102;
int adj[MX][MX];
int ans[MX][MX];
int tmp[MX][MX];

int n;

void mul() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[i][j] = ans[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tot = 0;
            for(int k = 0; k < n; k++) {
                tot += tmp[i][k] * adj[k][j];
            }
            ans[i][j] = (tot > 0);
        }
    }
}

void add() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tot = ans[i][j] + adj[i][j];
            ans[i][j] = (tot > 0);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            adj[i][j] = ans[i][j] = tmp;
        }
    }

    for(int i = 0; i < n; i++) {
        mul();
        add();
    }

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}