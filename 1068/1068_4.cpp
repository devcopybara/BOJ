// https://www.acmicpc.net/problem/1068
#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
vector<int> ch[MX];

int root = -1;
int x;

int dfs(int cur) {
    if(cur == x) return 0;

    int lCnt = 0;
    for(int nxt : ch[cur]) {
        lCnt += dfs(nxt);
    }
    return (lCnt ? lCnt : 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if(tmp == -1) root = i;
        else ch[tmp].push_back(i);
    }
    
    cin >> x;
    cout << dfs(root);
}