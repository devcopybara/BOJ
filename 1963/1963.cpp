// https://www.acmicpc.net/problem/1963
#include <bits/stdc++.h>
using namespace std;

vector<bool> state(10001, true);
vector<int> sieve(int n) {
    vector<int> primes;
    state[1] = false;
    for (int i = 2; i * i <= n; i++) {
    if (!state[i]) continue;
    for (int j = i * i; j <= n; j += i)
        state[j] = false;
    }
    for (int i = 2; i <= n; i++) {
        if (state[i]) primes.push_back(i);
    }
    return primes;
}

int dist[10001];
int set_digit_num(int a, int d, int i) {
    return a - ((a / d) % 10) * d + i * d;
}

int t, a, b;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes = sieve(10000);
    cin >> t;
    while(t--) {
        cin >> a >> b;

        fill(dist,dist+10000,-1);
        queue<int> q;
        
        dist[a] = 0;
        q.push(a);

        while(dist[b] == -1 && !q.empty()) {
            int cur = q.front(); q.pop();
            for(int d = 1; d <= 1000; d*=10) {
                for(int i = 0; i < 10; i++) {
                    if(d == 1000 && i == 0) continue; // 4자리 소수 유지
                    int nxt = set_digit_num(cur, d, i);
                    if(!state[nxt] || dist[nxt]!=-1) continue;
                    dist[nxt] = dist[cur]+1;
                    q.push(nxt);
                }
            }
        }
        
        cout << dist[b] << '\n';
    }
}