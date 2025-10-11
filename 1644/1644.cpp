#include <bits/stdc++.h>
using namespace std;
using uint64 = unsigned long long;

int n;
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
    cin >> n;
    sieve(n);

    vector<int> primes;
    for(int i = 2; i <= n; i++) {
        if(state[i]) primes.push_back(i);
    }
    int sz = primes.size();

    int ans = 0;
    int tot = 2;
    int en = 0;
    for(int st = 0; st < sz; st++) {
        while(en < sz && tot < n) {
            en++;
            if(en < sz) tot += primes[en];
        }
        if(en == sz) break;
        if(tot == n) ans++;
        tot -= primes[st];
    }
    cout << ans;
}