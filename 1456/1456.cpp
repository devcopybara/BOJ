#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uint64;
uint64 a, b;
const uint64 MX = 10000001; // 100000000000005;
vector<bool> state(MX, true);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    
    
    state[1] = false;
    for(uint64 i = 2; i*i <= MX; i++) {
        if(!state[i]) continue;
        
        for(uint64 j = i*i; j <= MX; j += i)
            state[j] = false;
    }
    
    
    uint64 ans = 0;
    for(uint64 i = 2; i <= MX; i++) {
        if(!state[i]) continue;
        
        for(uint64 j = i; j <= b / i; j *= i)
            if(j * i >= a)
                ans++;
    }
    cout << ans;
}