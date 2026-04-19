// https://www.acmicpc.net/problem/25515

// 현재 상태를 구하기 위해 이전 상태가 필요한가?
// 현재 상태 : d[0] : 루트 노드 시작 방문한 노드 정수 합의 최댓값
// 이전 상태 : d[i] :   i 노드 시작 방문한 노드 합의 최댓값
// d[0] += d[c0] (d[c0] > 0)

#include <bits/stdc++.h>
using namespace std;

const int64_t MX = 100'000;
vector<int64_t> adj[MX];
int64_t a[MX];
int64_t d[MX];

int64_t getD(int64_t cur) {
    d[cur] = a[cur];

    for(int64_t nxt : adj[cur]) {
        if(getD(nxt) <= 0) continue;
        d[cur] += d[nxt];
    }

    return d[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int64_t n; cin >> n;
    for(int64_t i = 0; i < n-1; i++) {
        int64_t p, c; cin >> p >> c;
        adj[p].push_back(c);
    }
    for(int64_t i = 0; i < n; i++) cin >> a[i];

    cout << getD(0);
}