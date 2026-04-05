// https://www.acmicpc.net/problem/1644
#include <bits/stdc++.h>
using namespace std;

const int MX = 4'000'005;
int a[MX];

vector<bool> state(4'000'005, true);

void sieve(int n) {
    state[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
            state[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    vector<int> primes;
    sieve(n);
    for(int i = 2; i <= n; i++) {
        if(state[i]) primes.push_back(i);
    }

    int ans = 0;
    int en = 0, sum = 0, sz = primes.size();
    for(int st = 0; st < sz; st++) {
        while(en < sz && sum < n) {
            sum += primes[en];
            en++;
        }
        if(sum < n) break;
        if(sum == n) ans++;
        sum -= primes[st];
    }
    cout << ans;
}