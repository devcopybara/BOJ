// https://www.acmicpc.net/problem/1368
#include <bits/stdc++.h>
using namespace std;
using t3int = tuple<int,int,int>;

#define MAX_COST 100'000

const int MX = 302;
int n;
int cost[MX];
int adj[MX][MX];
bool chk[MX];
int cnt;
priority_queue<t3int, vector<t3int>, greater<t3int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        cost[i] = tmp;
        pq.push({tmp,0,i});
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    int ans = 0;

    while(cnt < n) {
        auto [curW,curU,curV] = pq.top(); pq.pop();
        if(chk[curV]) continue;
        chk[curV] = 1;
        cnt++;

        ans += curW;

        for(int i = 1; i <= n; i++) {
            if(!chk[i] && adj[curV][i]) {
                pq.push({adj[curV][i],curV,i});
            }
        }
    }

    cout << ans;
}