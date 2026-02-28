// https://www.acmicpc.net/problem/1068
#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
int p[MX];
vector<int> ch[MX];

int root = -1;
int x;

int dfs(int cur) {
    if(cur == x) {
        if(x != root && ch[p[x]].size() == 1) return 1;
        return 0;
    }

    if(ch[cur].size() == 0) return 1;

    int cnt = 0;
    for(int nxt : ch[cur]) {
        cnt += dfs(nxt);
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        p[i] = tmp;

        if(tmp == -1) root = i;
        else ch[tmp].push_back(i);
    }
    
    cin >> x;
    cout << dfs(root);
}