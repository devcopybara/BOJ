// https://www.acmicpc.net/problem/14425
#include <bits/stdc++.h>
using namespace std;

map<string,int> nxt;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    while(n--) {
        string s; cin >> s;
        nxt[s] = 1;
    }

    int ans = 0;
    while(m--) {
        string s; cin >> s;
        ans += nxt[s];
    }
    cout << ans;
}