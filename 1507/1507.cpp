#include <bits/stdc++.h>
using namespace std;
int n;
int adj[20][20];
int comb[20][20];

bool iscomb() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(k == i || k == j) continue;
                if(adj[i][j] == adj[i][k]+adj[k][j]) 
                    comb[i][j] = 1;
                else if(adj[i][j] > adj[i][k]+adj[k][j]) 
                    return 0;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> adj[i][j];

    if(!iscomb()) cout << -1;
    else {
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(!comb[i][j]) ans += adj[i][j];
        cout << ans;
    }
}